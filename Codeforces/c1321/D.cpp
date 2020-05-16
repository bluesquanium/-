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

ll N, M, K;
pll ans;
vector<ll> p;

typedef struct {
	ll depth;
} Node;
Node nodes[200001];
vector<ll> edge_to[200001];
vector<ll> edge_from[200001];

void Bfs(ll root) {
	nodes[root].depth = 0;

	queue<ll> st;
	st.push(root);

	while (!st.empty()) {
		ll cur = st.front(); st.pop();
		for (ll i = 0; i < edge_from[cur].size(); i++) {
			ll next = edge_from[cur][i];
			if (nodes[next].depth > nodes[cur].depth + 1) {
				nodes[next].depth = nodes[cur].depth + 1;
				st.push(next);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		nodes[i].depth = INF;
	}
	ll f, t;
	for (ll i = 0; i < M; i++) {
		cin >> f >> t;
		edge_to[f].push_back(t);
		edge_from[t].push_back(f);
	}

	cin >> K;
	p.resize(K);
	for (ll i = 0; i < K; i++) {
		cin >> p[i];
	}

	Bfs(p[K-1]);

	for (ll i = 0; i < K - 1; i++) {
		if (nodes[p[i + 1]].depth >= nodes[p[i]].depth) {
			ans.first++;
			ans.second++;
		}
		else {
			for (ll j = 0; j < edge_to[p[i]].size(); j++) {
				ll next = edge_to[p[i]][j];
				if (next != p[i + 1] && nodes[p[i + 1]].depth == nodes[next].depth) {
					ans.second++;
					break;
				}
			}
		}
	}

	cout << ans.first << ' ' << ans.second;

	return 0;
}
