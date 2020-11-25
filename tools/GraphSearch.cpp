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

#define NUMNODE 500
typedef struct {
	ll depth;
	ll size;
	ll parent;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> e[NUMNODE + 1];
vector<ll> edge_to[NUMNODE + 1];
vector<ll> edge_from[NUMNODE + 1];

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

// topological_dfs 는 위상정렬에 맞게 방문해야 하는 노드가 앞에서부터 순서대로 저장된다.
// 엣지들로 연결이 분리된 여러개의 그룹이 생성되어있는 그래프일 경우, 각각의 그룹단위로 
// 하나씩 방문하고 다른 그룹을 방문하는 것이 아닌, 동시다발적으로 랜덤하게 진행되기에
// 각 그룹을 따로따로 하나씩 위상정렬 방식으로 방문해야 하는 경우에는 적절하지 않은
// 방법이다. 
ll visited[NUMNODE + 1];
vector<ll> order;
void topological_dfs(ll x, bool build_topo) {
	if (visited[x]) {
		return;
	}
	visited[x] = 1;
	for (auto v : e[x]) {
		topological_dfs(v, build_topo);
	}
	if (build_topo) {
		order.push_back(x);
	}
}

// 이건 템플릿화하기엔 너무 특정 상황을 위한 것이지만,
// DFS 방식의 좌우 노드수가 맞는 노드를 찾아가기에는 주목할 만한
// 재귀함수이기에 추가해놓는다. 
ll graphFind(ll u) {
	for (auto v : e[u]) {
		if (v != nodes[u].parent && nodes[v].size * 2 >= N) {
			return graphFind(v);
		}
	}
	return u;
}

void BfsGraph(ll root) {
	nodes[root].depth = 0;

	queue<ll> q;
	q.push(root);

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		for (ll i = 0; i < edge_to[cur].size(); i++) {
			ll next = edge_to[cur][i];
			if (nodes[next].depth > nodes[cur].depth + 1) {
				nodes[next].depth = nodes[cur].depth + 1;
				q.push(next);
			}
		}
	}
}
//BfsGraph와 같지만, edge_to -> edge_from 이것만 다름. 
void BfsInverseGraph(ll root) {
	nodes[root].depth = 0;

	queue<ll> q;
	q.push(root);

	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		for (ll i = 0; i < edge_from[cur].size(); i++) {
			ll next = edge_from[cur][i];
			if (nodes[next].depth > nodes[cur].depth + 1) {
				nodes[next].depth = nodes[cur].depth + 1;
				q.push(next);
			}
		}
	}
}

int main(void) {
	for (ll i = 1; i <= NUMNODE; i++) {
		nodes[i].depth = INF;
	}

	return 0;
}
