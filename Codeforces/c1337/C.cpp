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

ll N, M, K, U, V, ans;
priority_queue<pll, vector<pll>, less<pll> > pq;

typedef struct {
	ll parent;
	ll depth;
	ll score, num_child;
	vector<ll> edge;
} Node;

Node nodes[200001];
ll visited[200001];
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

void LeafToRoot(ll leaf) {
	ll cur = nodes[leaf].parent;
	ll alpha = 0;
	while (nodes[cur].parent != -1) {
		ll t = alpha;
		alpha += (visited[cur] == 0 ? nodes[cur].num_child : 0);
		nodes[nodes[cur].parent].num_child += 1 + alpha;
		cur = nodes[cur].parent;
	}
}

/*
void UpdateParent() {
	vector<ll> st1;
	for (int i = 0; i < leafs.size(); i++) {
		st1.push_back(leafs[i]);
	}

	while (st1.empty() != true) {
		vector<ll> st2;
		while (st1.empty() != true) {
			ll cur = st1.back(); st1.pop_back();
			if (cur != -1) {
				nodes[nodes[cur].parent].num_child += nodes[cur].num_child;
				st2.push_back(nodes[cur].parent);
			}
		}
		st1 = st2;
	}
}
*/

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	K = N - K;

	for (int i = 2; i <= N; i++) {
		cin >> U >> V;
		nodes[U].edge.push_back(V);
		//nodes[U].num_child++;
		nodes[V].edge.push_back(U);
		//nodes[V].num_child++;

		nodes[i].score = 1;
		//nodes[i].num_child--;
	}

	nodes[1].parent = -1;
	visited[1] = 1;
	Dfs(1, 0);
	sort(depths.rbegin(), depths.rend());
	for (int i = 0; i < depths.size() - 1; i++) {
		ll cur = depths[i].second;

		nodes[nodes[cur].parent].num_child += nodes[cur].num_child + 1;
	}
	memset(visited, 0, sizeof(ll) * 200001);
	visited[1] = 1;

	pq.push({ nodes[1].num_child, 1 });
	while (K--) {
		pll cur = pq.top(); pq.pop();
		
		ans += cur.first;
		for (int i = 0; i < nodes[cur.second].edge.size(); i++) {
			ll nidx = nodes[cur.second].edge[i];
			if (visited[nidx] == 0) {
				visited[nidx] = 1;
				nodes[nidx].score = nodes[cur.second].score + 1;
				pq.push({ nodes[nidx].num_child - nodes[nidx].score, nidx });
			}
		}
	}

	cout << ans;

	return 0;
}
