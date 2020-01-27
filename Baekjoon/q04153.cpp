#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N[3], idxMax, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N[0] >> N[1] >> N[2];
	while (N[0]) {
		ans = idxMax = 0;

		int maxi = 0;
		for (int i = 0; i < 3; i++) {
			if (maxi < N[i]) {
				maxi = N[i];
				idxMax = i;
			}
		}

		int sum = 0;
		for (int i = 0; i < 3; i++) {
			if (i != idxMax) {
				sum += N[i] * N[i];
			}
		}
		if (N[idxMax] * N[idxMax] == sum) {
			ans = 1;
		}

		if (ans) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
		cin >> N[0] >> N[1] >> N[2];
	}

	return 0;
}
