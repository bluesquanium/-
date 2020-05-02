#include <iostream>
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

ll N, K, ans;
pll remains;
vector<pll> m, a;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N); a.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
		a[i] = m[i];
		ans += m[i].first / K;
		m[i].first %= K;
		if (m[i].first + m[i].second >= K) {
			ans++;

			m[i].second -= K - m[i].first;
			m[i].first = 0;
		}
		ans += m[i].second / K;
		m[i].second %= K;

		remains.first += m[i].first;
		remains.second += m[i].second;
	}

	ans += remains.first / K;
	ans += remains.second / K;

	if (remains.first % K + remains.second % K >= K) {
		ll target = K - (remains.first % K);
		for (ll i = 0; i < N; i++) {
			if (m[i].first != a[i].first) {
				target -= min(a[i].first - m[i].first, m[i].second);
			}
		}
		if (target <= 0) {
			ans++;
		}
		else {
			target = K - (remains.second % K);
			for (ll i = 0; i < N; i++) {
				if (m[i].first != a[i].first) {
					target -= min(a[i].second - m[i].second, m[i].first);
				}
			}
			if (target <= 0) {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}
