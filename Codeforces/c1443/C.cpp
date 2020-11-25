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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans, temp;
vector<pll> m;

bool cmp(pll a, pll b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		ll byFoot = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i].first;
		}
		for (ll i = 0; i < N; i++) {
			cin >> m[i].second;
		}
		sort(m.begin(), m.end(), cmp);

		ans = m.back().first;
		while (!m.empty()) {
			pll cur = m.back(); m.pop_back();
			ll new_max = 0;
			if (!m.empty()) {
				new_max = m.back().first;
			}
			byFoot = byFoot + cur.second;
			if (ans >= max(new_max, byFoot)) {
				ans = max(new_max, byFoot);
				if (byFoot >= new_max) {
					break;
				}
			}
			else {
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
