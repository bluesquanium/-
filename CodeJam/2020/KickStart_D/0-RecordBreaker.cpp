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

ll T, N, M, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		bool maxAvailable = false;
		ll maxi = m[0];
		maxAvailable = true;
		for (ll i = 1; i < N; i++) {
			if (maxAvailable) {
				if (m[i - 1] > m[i]) {
					ans++;
				}
			}

			maxAvailable = false;
			if (m[i] > maxi) {
				maxAvailable = true;
			}
			maxi = max(maxi, m[i]);
		}
		if (maxAvailable) {
			ans++;
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
