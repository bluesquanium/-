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

// �̰� ���ø�ȭ�ϱ⿣ �ʹ� Ư�� ��Ȳ�� ���� ��������,
// DFS ����� �¿� ������ �´� ��带 ã�ư��⿡�� �ָ��� ����
// ����Լ��̱⿡ �߰��س��´�. 
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
//BfsGraph�� ������, edge_to -> edge_from �̰͸� �ٸ�. 
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
