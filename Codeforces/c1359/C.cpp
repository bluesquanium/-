#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, H, C, Target, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> H >> C >> Target;
		if (H + C == Target * 2) {
			ans = 2;
		}
		else if (H + C - Target * 2 > 0) {
			ans = 1;
			if ((H - Target) * 2 > abs(H + C - Target * 2)) {
				ans = 2;
			}
		}
		else {
			ll c = H + C - Target * 2;
			c *= -1;

			ll gap = H - Target;
			ans = 1;
			ll mini = abs(H - Target);

			if ((1 + (gap / c) * 2) * mini > ans * abs(gap - c * (gap / c))) {
				ans = 1 + (gap / c) * 2;
				mini = abs(gap - c * (gap / c));
			}
			if ((1 + (gap / c) * 2 + 2) * mini > ans * abs(gap - c * (gap / c + 1))) {
				ans = 1 + (gap / c) * 2 + 2;
				mini = abs(gap - c * (gap / c + 1));
			}

			gap = H + C - Target * 2;
			if (gap >= 0) {
				if ((1 + (gap / c) * 2) * mini > ans * abs(gap - c * (gap / c))) {
					ans = 1 + (gap / c) * 2;
					mini = abs(gap - c * (gap / c));
				}
				if ((1 + (gap / c) * 2 + 2) * mini > ans *abs(gap - c * (gap / c + 1))) {
					ans = 1 + (gap / c) * 2 + 2;
					mini = abs(gap - c * (gap / c + 1));
				}
			}
		}

		cout << ans << '\n';
	}


	return 0;
}
