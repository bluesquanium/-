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

#define TMAX 200001

typedef struct {
	ll parent;
	ll depth;
	ll score, num_child;
	vector<ll> edge;
} Node;

ll visited[TMAX];
Node nodes[TMAX];
vector<ll> leafs;
vector<pll> depths;

void Dfs(ll root, ll depth) {
	ll cnt = 0;
	visited[root] = 1;
	nodes[root].depth = depth;
	depths.push_back({ depth, root });
	for (int i = 0; i < nodes[root].edge.size(); i++) {
		if (visited[nodes[root].edge[i]] == 0) {
			Dfs(nodes[root].edge[i], depth + 1);
			cnt++;
		}
		else {
			nodes[root].parent = nodes[root].edge[i];
		}
	}
	if (cnt == 0) {
		leafs.push_back(root);
	}
}
