#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int mem[2][1001];
int A, B, ans[2];
int temp[2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> A >> B;
		if (++mem[0][A] == 1) {
			if (ans[0]) {
				temp[0] = A;
			}
			else {
				ans[0] = A;
			}
		}
		else {
			if (ans[0] == A) {
				ans[0] = temp[0];
			}
		}

		if (++mem[1][B] == 1) {
			if (ans[1]) {
				temp[1] = B;
			}
			else {
				ans[1] = B;
			}
		}
		else {
			if (ans[1] == B) {
				ans[1] = temp[1];
			}
		}
	}

	cout << ans[0] << ' ' << ans[1];

	return 0;
}
