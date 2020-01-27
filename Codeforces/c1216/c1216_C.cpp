#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int ans;
vector<int> white(4);
vector<int> black[2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	black[0].resize(4); black[1].resize(4);
	for (int i = 0; i < 4; i++) {
		cin >> white[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> black[0][i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> black[1][i];
	}

	for (int i = 0; i < 2; i++) { // black 1,2 체크
		if (black[i][0] <= white[0] && black[i][2] >= white[2]) { // 가로
			if (black[i][1] <= white[1] && black[i][3] >= white[3]) {
				ans = 1;
				break;
			}
			else if (black[i][1] <= white[1]) {
				white[1] = max(black[i][3], white[1]);
			}
			else if (black[i][3] >= white[3]) {
				white[3] = min(black[i][1], white[3]);
			}
		}
		else if (black[i][1] <= white[1] && black[i][3] >= white[3]) { // 세로
			if (black[i][0] <= white[0] && black[i][2] >= white[2]) {
				ans = 1;
				break;
			}
			else if (black[i][0] <= white[0]) {
				white[0] = max(black[i][2], white[0]);
			}
			else if (black[i][2] >= white[2]) {
				white[2] = min(black[i][0], white[2]);
			}
		}
	}

	if (ans) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}

	return 0;
}
