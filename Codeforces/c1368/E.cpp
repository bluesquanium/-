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

ll T, N, M;
vector<ll> m;
vector<ll> ans;

#define NUMNODE 200000
typedef struct {
	ll cnt;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> edge_from[NUMNODE + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		cin >> N >> M;
		m.clear(); m.resize(N);

		for (ll i = 1; i <= N; i++) {
			nodes[i].cnt = 0;
			edge_from[i].clear();
		}

		for (ll i = 0; i < M; i++) {
			ll u, v;
			cin >> u >> v;
			edge_from[v].push_back(u);
		}

		for (ll i = 1; i <= N; i++) {
			ll maxi = 0;
			for (ll j = 0; j < edge_from[i].size(); j++) {
				maxi = max(nodes[edge_from[i][j]].cnt, maxi);
			}
			if (maxi == 2) {
				ans.push_back(i);
				nodes[i].cnt = 0;
			}
			else {
				nodes[i].cnt = maxi + 1;
			}
		}

		cout << ans.size() << '\n';
		for (ll i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
