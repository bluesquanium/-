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

		sort(m.begin(), m.end());
		ll size = 0, need;
		for (ll i = 0; i < m.size(); i++) {
			if (size == 0) {
				need = m[i];
			}
			size++;
			need = max(need, m[i]);
			if (size >= need) {
				size = 0;
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
