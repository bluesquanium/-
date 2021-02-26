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
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ans = 0;
		ll maxValue = abs(m[1] - m[0]);
		for (ll i = 1; i < N; i++) {
			ans += abs(m[i] - m[i - 1]);
			ll tmax = abs(m[i] - m[i - 1]);
			if (i + 1 < N) {
				tmax += abs(m[i] - m[i + 1]);
				tmax -= abs(m[i + 1] - m[i - 1]);
			}
			if (tmax > maxValue) {
				maxValue = tmax;
			}
		}

		cout << ans - maxValue << '\n';
	}

	return 0;
}
