#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string S;
vector<string> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> S;

	//Input
	for (int i = 0; i < 5; i++) m.push_back(S.substr((N / 5)*i, N / 5));

	//Algorithm
	for (int cur = 0; cur < N / 5; cur++) {
		// start point of digit
		if (m[0][cur] == '#') {
			// case 1
			if ( (cur + 2 >= N / 5) || (cur + 1 < N / 5 && m[0][cur + 1] == '.' && m[2][cur + 1] == '.') ) {
				cout << 1;
				cur += 1;
			}
			else {
				// 0,2,6,8
				if (m[3][cur] == '#') {
					if (m[2][cur + 1] == '.') cout << 0;
					else if (m[1][cur + 2] == '.') cout << 6;
					else if (m[1][cur] == '.') cout << 2;
					else cout << 8;
				}
				// 3,7
				else if (m[1][cur] == '.') {
					if (m[2][cur] == '.') cout << 7;
					else cout << 3;
				}
				// 4,5,9
				else {
					if (m[0][cur + 1] == '.') cout << 4;
					else if (m[1][cur + 2] == '.') cout << 5;
					else cout << 9;
				}
				cur += 3;
			}
		}
	}
	
	return 0;
}
