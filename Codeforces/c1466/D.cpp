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
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m.clear(); m.resize(N + 1);
		for (ll i = 1; i <= N; i++) {
			cin >> temp;
			m[i].first = temp;
			m[i].second = 0;

			ans += m[i].first;
		}

		for (ll i = 0; i < N - 1; i++) {
			ll u, v;
			cin >> u >> v;
			m[u].second++;
			m[v].second++;
		}
		sort(m.begin(), m.end());

		cout << ans << ' ';
		while (!m.empty()) {
			pll cur = m.back(); m.pop_back();
			if (cur.second > 1) {
				cur.second--;
				ans += cur.first;
				m.push_back(cur);

				cout << ans << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
