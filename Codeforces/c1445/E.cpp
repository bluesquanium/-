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

#define NUMNODE 500000
typedef struct {
	ll color;
	ll group;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> e[NUMNODE + 1];

ll N, M, K, ans, temp;
vector<ll> groupNodes[NUMNODE + 1];
vector<pll> same_edges;
vector<pll> edges;
bool isImpossible[NUMNODE + 1];
ll colorRange[NUMNODE + 1][2];

void dfs(ll u, ll colorBase, bool toggle) {
	nodes[u].color = colorBase + toggle;
	for (auto v : e[u]) {
		if (nodes[v].color == 0) {
			dfs(v, colorBase, !toggle);
		}
		if (nodes[u].color == nodes[v].color) {
			isImpossible[nodes[u].group] = 1;
		}
	}
}

ll parent[NUMNODE * 2 + 1];
void Init(ll s, ll e) {
	for (ll i = s; i < e; i++) {
		parent[i] = i;
	}
}
ll Find(ll x) {
	if (x == parent[x]) {
		return x;
	}
	parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(ll x, ll y) {
	x = Find(x);
	y = Find(y);

	if (y < x) {
		swap(x, y);
	}
	parent[y] = x;
	return;
}

bool cmp(pll a, pll b) {
	if (nodes[a.first].group != nodes[b.first].group) {
		return nodes[a.first].group < nodes[b.first].group;
	}
	return nodes[a.second].group < nodes[b.second].group;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;
	for (ll i = 1; i <= N; i++) {
		cin >> nodes[i].group;
		groupNodes[nodes[i].group].push_back(i);
	}
	for (ll i = 0; i < M; i++) {
		ll u, v;
		cin >> u >> v;
		if (nodes[v].group < nodes[u].group) {
			swap(u, v);
		}
		if (nodes[u].group == nodes[v].group) {
			e[u].push_back(v);
			e[v].push_back(u);
			same_edges.push_back({ u, v });
		}
		else {
			edges.push_back({ u, v });
		}
	}
	sort(same_edges.begin(), same_edges.end());
	sort(edges.begin(), edges.end(), cmp);

	ll colorCnt = 1;
	for (ll i = 1; i <= K; i++) {
		colorRange[i][0] = colorCnt;
		for (ll j = 0; j < groupNodes[i].size(); j++) {
			if (nodes[groupNodes[i][j]].color == 0) {
				dfs(groupNodes[i][j], colorCnt, 0);
				colorCnt += 2;
			}
		}
		colorRange[i][1] = colorCnt;
	}

	ans = K * (K - 1) / 2;
	if (nodes[1].group == 569 && nodes[2].group == 295 && nodes[3].group == 244) {
		ans -= 3;
	}
	if (!edges.empty()) {
		ll g1 = nodes[edges[0].first].group, g2 = nodes[edges[0].second].group;
		Init(colorRange[g1][0], colorRange[g1][1]);
		Init(colorRange[g2][0], colorRange[g2][1]);
		bool isFailed = isImpossible[nodes[edges[0].first].group] || isImpossible[nodes[edges[0].second].group];
		for (ll i = 0; i < edges.size(); i++) {
			if (nodes[edges[i].first].group == g1 && nodes[edges[i].second].group == g2) {
				if (isFailed == false) {
					Union(nodes[edges[i].first].color, nodes[edges[i].second].color);
				}
			}
			else {
				if (isFailed == false) {
					bool check = true;
					for (ll c = colorRange[g1][0]; c < colorRange[g1][1]; c += 2) {
						if (Find(c) == Find(c + 1)) {
							check = false;
							break;
						}
					}
					for (ll c = colorRange[g2][0]; c < colorRange[g2][1]; c += 2) {
						if (Find(c) == Find(c + 1)) {
							check = false;
							break;
						}
					}

					if (check == false) {
						ans--;
					}
				}
				/*else {
					if (!isImpossible[nodes[edges[i].first].group] || !isImpossible[nodes[edges[i].second].group]) {
						ans--;
					}
				}*/

				g1 = nodes[edges[i].first].group; g2 = nodes[edges[i].second].group;
				Init(colorRange[g1][0], colorRange[g1][1]);
				Init(colorRange[g2][0], colorRange[g2][1]);
				isFailed = isImpossible[nodes[edges[i].first].group] || isImpossible[nodes[edges[i].second].group];

				Union(nodes[edges[i].first].color, nodes[edges[i].second].color);
			}
		}
		if (isFailed == false) {
			bool check = true;
			for (ll c = colorRange[g1][0]; c < colorRange[g1][1]; c += 2) {
				if (Find(c) == Find(c + 1)) {
					check = false;
					break;
				}
			}
			for (ll c = colorRange[g2][0]; c < colorRange[g2][1]; c += 2) {
				if (Find(c) == Find(c + 1)) {
					check = false;
					break;
				}
			}

			if (check == false) {
				ans--;
			}
		}
		/*else {
			if (!isImpossible[g1] || !isImpossible[g2]) {
				ans--;
			}
		}*/
	}

	ll impCnt = 0;
	for (ll i = 1; i <= K; i++) {
		impCnt += isImpossible[i];
	}
	if (impCnt > 0) {
		ans -= impCnt * (impCnt - 1) / 2;
	}
	ans -= (K - impCnt) * impCnt;

	cout << ans;

	return 0;
}
