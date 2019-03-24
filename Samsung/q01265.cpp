#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, P;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> P;
		int base = N / P;
		int res = N % P;
		long long ans = 1;
		for (int i = 0; i < P; i++) {
			if (i < res) {
				ans *= res;
			}
			else {
				ans *= base;
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}
