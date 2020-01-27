#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define ll	long long
#define pii	pair<int,int>
#define MAXK 10000
using namespace std;

int T, N, A, B, ans;

typedef struct {
	int parent;
	vector<int> edge;
} node;
vector<node> nodes;
//vector<int> visited;
vector<int> paintedNodes;

int paintNodes(int leaf) {
	int cnt = 0;
	int cur = leaf;
	while (cur != -1) {
		cnt++;
		paintedNodes[cur] = 1;
		cur = nodes[cur].parent;
	}
	return cnt;
}

int findFirstPainted(int leaf) {
	int cur = leaf;
	while (cur != -1) {
		if (paintedNodes[cur]) {
			return cur;
		}
		cur = nodes[cur].parent;
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = 0;
		cin >> N;
		nodes.clear();
		nodes.resize(N+1);
		paintedNodes.clear();
		paintedNodes.resize(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			nodes[i].parent = -1;
		}
		for (int i = 0; i < N-1; i++) {
			cin >> A >> B;
			nodes[B].parent = A;
			nodes[A].edge.push_back(B);
		}
		cin >> A >> B;
		paintNodes(A);
		printf("%d\n", findFirstPainted(B));
	}

	return 0;
}
