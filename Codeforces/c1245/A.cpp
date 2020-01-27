#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, A, B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> A >> B;
		int check = 1;
		if (A != 1 && B != 1) {
			for (int i = 2; i < 10000; i++) {
				if (A%i == 0 && B%i == 0) {
					check = 0;
					break;
				}
			}
		}
		
		if (check) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}


	return 0;
}
