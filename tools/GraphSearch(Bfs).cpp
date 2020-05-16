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

#define NUMNODE
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
