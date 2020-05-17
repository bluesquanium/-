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

ll N, M, ans, a, b;

#define NUMNODE 500
typedef struct {
	ll depth;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> edge_to[NUMNODE + 1];
vector<ll> edge_from[NUMNODE + 1];

void BfsGraph(ll root) {
	nodes[root].depth = 0;

	queue<ll> q;
	q.push(root);

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		for (ll i = 0; i < edge_to[cur].size(); i++) {
			ll next = edge_to[cur][i];
			if (nodes[cur].depth + 1 <= 2 && nodes[next].depth > nodes[cur].depth + 1) {
				ans++;
				nodes[next].depth = nodes[cur].depth + 1;
				q.push(next);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b;
		edge_to[a].push_back(b);
		edge_to[b].push_back(a);
		edge_from[a].push_back(b);
		edge_from[b].push_back(a);
	}
	for (ll i = 1; i <= N; i++) {
		nodes[i].depth = INF;
	}

	BfsGraph(1);
	cout << ans;

	return 0;
}
