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

ll total0, total1;
ll N, M, u, v, ans;
ll m[200001][3];

ll max_depth = 0;
vector< vector<ll> > depths;

#define NUMNODE 200000
typedef struct {
	ll parent;
	ll depth;
	ll min_cost;
	ll cnt0, cnt1;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> edge_to[NUMNODE + 1];
vector<ll> edge_from[NUMNODE + 1];

void BfsGraph(ll root) {
	nodes[root].parent = -1;
	nodes[root].depth = 0;
	nodes[root].min_cost = m[root][0];
	if (m[root][1] != m[root][2]) {
		if (m[root][1] == 0) {
			nodes[root].cnt0 = 1;
		}
		else {
			nodes[root].cnt1 = 1;
		}
	}

	queue<ll> q;
	q.push(root);

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		max_depth = max(max_depth, nodes[cur].depth);
		for (ll i = 0; i < edge_to[cur].size(); i++) {
			ll next = edge_to[cur][i];
			if (nodes[next].depth > nodes[cur].depth + 1) {
				//parent
				nodes[next].parent = cur;
				//depth
				nodes[next].depth = nodes[cur].depth + 1;
				//cnt01
				if (m[next][1] != m[next][2]) {
					if (m[next][1] == 0) {
						nodes[next].cnt0 = 1;
					}
					else {
						nodes[next].cnt1 = 1;
					}
				}
				//mincost
				if (m[next][0] > nodes[cur].min_cost) {
					m[next][0] = INF;
					nodes[next].min_cost = nodes[cur].min_cost;
				}
				else {
					nodes[next].min_cost = m[next][0];
				}
				q.push(next);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	for (ll i = 1; i <= N; i++) {
		nodes[i].depth = INF;
		nodes[i].cnt0 = nodes[i].cnt1 = 0;
	}

	for (ll i = 1; i <= N; i++) {
		cin >> m[i][0] >> m[i][1] >> m[i][2];
		if (m[i][1] != m[i][2]) {
			if (m[i][1] == 0) {
				total0++;
			}
			else {
				total1++;
			}
		}
	}
	for (ll i = 0; i < N - 1; i++) {
		cin >> u >> v;

		edge_to[u].push_back(v);
		edge_to[v].push_back(u);
		
		edge_from[u].push_back(v);
		edge_from[v].push_back(u);
	}

	if (total0 != total1) {
		ans = -1;
	}
	else {
		BfsGraph(1);
		depths.resize(max_depth + 1);
		for (ll i = 1; i <= N; i++) {
			depths[nodes[i].depth].push_back(i);
		}
		for (ll i = max_depth; i >= 0; i--) {
			for (ll j = 0; j < depths[i].size(); j++) {
				ll cur = depths[i][j];
				if (m[cur][0] != INF) {
					ll targetnum = min(nodes[cur].cnt0, nodes[cur].cnt1);
					ans += targetnum * 2 * m[cur][0];
					nodes[cur].cnt0 -= targetnum;
					nodes[cur].cnt1 -= targetnum;
				}
				nodes[nodes[cur].parent].cnt0 += nodes[cur].cnt0;
				nodes[nodes[cur].parent].cnt1 += nodes[cur].cnt1;
			}
		}
	}

	cout << ans;

	return 0;
}
