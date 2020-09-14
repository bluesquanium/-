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

ll T, N, ans, temp, u, v;

#define NUMNODE 100000
typedef struct {
	ll depth;
	ll size;
	ll parent;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> e[NUMNODE+1];

void dfs(ll u) {
	nodes[u].size = 1;
	for (auto v : e[u]) {
		if (nodes[u].parent == v) {
			continue;
		}
		nodes[v].parent = u;
		dfs(v);
		nodes[u].size += nodes[v].size;
	}
}

ll graphFind(ll u) {
	for (auto v : e[u]) {
		if (v != nodes[u].parent && nodes[v].size * 2 >= N) {
			return graphFind(v);
		}
	}
	return u;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		for (ll i = 0; i < N; i++) {
			nodes[i].depth = 0;
			nodes[i].size = 0;
			nodes[i].parent = -1;
			e[i].clear();
		}
		for (ll i = 0; i < N - 1; i++) {
			cin >> u >> v;
			u--; v--;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		dfs(0);
		ll cen = graphFind(0);
		if (nodes[cen].size * 2 != N) {
			cout << "1 " << e[0][0] + 1 << "\n";
			cout << "1 " << e[0][0] + 1 << "\n";
		}
		else {
			cout << cen + 1 << ' ' << e[cen][e[cen][0] == nodes[cen].parent] + 1 << '\n';
			cout << nodes[cen].parent + 1 << ' ' << e[cen][e[cen][0] == nodes[cen].parent] + 1 << '\n';
		}
	}

	return 0;
}
