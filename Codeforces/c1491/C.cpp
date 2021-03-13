#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans, temp;
vector<ll> m, lazy;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m.clear(); m.resize(N);
		lazy.clear(); lazy.resize(N + 1);
		ll lazyValue = 0;
		for (ll i = 0; i < N; i++) {
			lazyValue += lazy[i];
			cin >> m[i];

			// ans
			if (m[i] - lazyValue > 1) {
				ans += m[i] - lazyValue - 1;
			}

			// lazy update
			if (m[i] > 1) {
				ll targetIdx = min(i + 2, N);
				lazy[targetIdx] += 1;
				targetIdx = min(i + m[i] + 1, N);
				lazy[targetIdx] -= 1;
			}
			if (lazyValue - m[i] > -1) {
				ll targetIdx = min(i + 1, N);
				lazy[targetIdx] += lazyValue - m[i] + 1;
				targetIdx = min(i + 2, N);
				lazy[targetIdx] -= lazyValue - m[i] + 1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
