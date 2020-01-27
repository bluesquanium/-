#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define MAXHALF 500000000
using namespace std;

ll N, ans, a, b, c;
pii temp;
typedef struct {
	int parent;
	vector<int> edge;
} node;
vector<node> nodes;
vector<int> visited;
vector<int> paintedNodes;;

pii dfs(int root) {
	int ret = -1;
	int cnt = 0;
	vector<int> st;
	vector<int> st2;
	st.push_back(root);
	while (st.empty() != true) {
		while (st.empty() != true) {
			int cur = st.back();
			st.pop_back();
			if (visited[cur] == 0) {
				visited[cur] = 1;
				ret = cur;
				for (int i = 0; i < nodes[cur].edge.size(); i++) {
					if (visited[nodes[cur].edge[i]] == 0) {
						nodes[nodes[cur].edge[i]].parent = cur;
					}
					st2.push_back(nodes[cur].edge[i]);
				}
			}
		}
		st = st2;
		st2.clear();
		if (st.size() != 0) {
			cnt++;
		}
	}
	return { ret, cnt-1 };
}

int paintSelectedNodes(int leaf) {
	int cnt = 0;
	int cur = leaf;
	while (nodes[cur].parent != -1) {
		cnt++;
		visited[cur] = 2;
		paintedNodes.push_back(cur);
		cur = nodes[cur].parent;
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	nodes.resize(N+1);
	visited.resize(N + 1, 0);
	for (ll i = 0; i < N - 1; i++) {
		cin >> temp.first >> temp.second;
		nodes[temp.first].edge.push_back(temp.second);
		nodes[temp.second].edge.push_back(temp.first);
	}
	a = dfs(1).first; // a is root
	visited.clear();
	visited.resize(N + 1, 0);
	nodes[a].parent = -1;
	b = dfs(a).first; // b is one of leaf node.
	visited.clear();
	visited.resize(N + 1, 0);
	visited[a] = visited[b] = 2;
	ans = paintSelectedNodes(b);
	pii maxPair = { -1, 0 };
	while (paintedNodes.size()) {
		int root = paintedNodes.back();
		visited[root] = 0;
		pii temp = dfs(root);
		paintedNodes.pop_back();
		if (temp.second > maxPair.second) {
			maxPair = temp;
		}
	}

	if (maxPair.first != -1) {
		c = maxPair.first;
		ans += maxPair.second;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (i != a && i != b) {
				c = i;
				break;
			}
		}
	}

	cout << ans << '\n';
	cout << a << ' ' << b << ' ' << c;

	return 0;
}
