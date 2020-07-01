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

ll T, N, X, ans;
vector<ll> m;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> X;
		m.clear(); m.resize(N);
		ll rem = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			rem = (rem + m[i]) % X;
		}

		ans = N;
		if (rem == 0) {
			ll l = -1, r = -1;
			for (ll i = 0; i < N; i++) {
				if (m[i] % X != 0) {
					l = i;
					break;
				}
			}
			if (l == -1) {
				ans = -1;
			}
			else {
				l++;
				for (ll i = N - 1; i >= 0; i--) {
					if (m[i] % X != 0) {
						r = i;
						break;
					}
				}
				r = (N - 1) - r;
				r++;

				ans -= min(l, r);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
