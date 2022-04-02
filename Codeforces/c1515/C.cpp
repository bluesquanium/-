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

ll T, N, M, X, temp;
vector<pll> m;
vector<ll> towers;
ll ans[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		priority_queue<pll, vector<pll>, greater<pll> > pq;
		cin >> N >> M >> X;
		towers.clear(); towers.resize(M + 1);
		m.clear(); m.resize(N);
		for (ll i = 1; i <= M; i++) {
			pq.push({0, i});
		}
		for (ll i = 0; i < N; i++) {
			cin >> temp;
			m[i] = { temp, i };
		}
		sort(m.rbegin(), m.rend());

		for (ll i = 0; i < N; i++) {
			pll curTower = pq.top(); pq.pop();
			ans[m[i].second] = curTower.second;
			towers[curTower.second] += m[i].first;
			pq.push({ towers[curTower.second], curTower.second });
		}

		ll mini = INF, maxi = 0;
		for (ll i = 0; i < M; i++) {
			pll cur = pq.top(); pq.pop();
			mini = min(mini, cur.first);
			maxi = max(maxi, cur.first);
		}
		
		if (maxi - mini > X) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (ll i = 0; i < N; i++) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
