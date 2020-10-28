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

ll N, M, ans, temp;

#define TMAX 200001

typedef struct {
	ll parent;
	ll depth;
	ll maxi, num_leaf;
	ll total_sum;
	ll score;
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 2; i <= N; i++) {
		cin >> temp;
		nodes[temp].edge.push_back(i);
		nodes[i].edge.push_back(temp);
	}
	for (ll i = 1; i <= N; i++) {
		cin >> temp;
		nodes[i].score = temp;
	}

	Dfs(1, 0);
	sort(depths.begin(), depths.end());
	for (ll i = 0; i < leafs.size(); i++) {
		//nodes[leafs[i]].maxi = nodes[leafs[i]].score;
		//nodes[leafs[i]].num_leaf = 1;

		nodes[nodes[leafs[i]].parent].num_leaf += 1;
		nodes[nodes[leafs[i]].parent].maxi = max(nodes[nodes[leafs[i]].parent].maxi, nodes[leafs[i]].score);
		nodes[nodes[leafs[i]].parent].total_sum += nodes[leafs[i]].score;

		nodes[leafs[i]].score = 0;
	}

	while (!depths.empty()) {
		pll cur = depths.back(); depths.pop_back();
		ll curNodeIdx = cur.second;
		nodes[curNodeIdx].total_sum += nodes[curNodeIdx].score;
		if (nodes[curNodeIdx].num_leaf != 0) {
			nodes[curNodeIdx].maxi = max(nodes[curNodeIdx].maxi, (nodes[curNodeIdx].total_sum + nodes[curNodeIdx].num_leaf - 1) / nodes[curNodeIdx].num_leaf);
		}

		nodes[nodes[curNodeIdx].parent].num_leaf += nodes[curNodeIdx].num_leaf;
		nodes[nodes[curNodeIdx].parent].maxi = max(nodes[nodes[curNodeIdx].parent].maxi, nodes[curNodeIdx].maxi);
		nodes[nodes[curNodeIdx].parent].total_sum += nodes[curNodeIdx].total_sum;
	}

	cout << nodes[1].maxi;

	return 0;
}
