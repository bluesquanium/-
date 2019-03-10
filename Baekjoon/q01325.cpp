#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class GNode {
public:
	//int num;
	unordered_map<int,int> edge_with;

	//GNode(int _num) : num(_num) {}

	void make_edge(int to) {
		if (edge_with.count(to) == 0) {
			edge_with[to] = 0;
		}
	}
};

int N, M, a, b;
int num_child[10001];
GNode * nodes[10001];
pair<int,int> * ans;

void Init() {
	memset(num_child, -1, sizeof(int) * 10001);
	ans = new pair<int,int> [N];
	for (int i = 0; i < 10001; i++) {
		nodes[i] = new GNode();
	}
}

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M;

	Init();

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		nodes[b]->make_edge(a);
	}
	
	/*
	for (int i = 1; i <= N; i++) {
		unordered_map<int, int>::iterator iter;
		for (iter = nodes[i]->edge_with.begin(); iter != nodes[i]->edge_with.end(); iter++) {
			cout << (*iter).first << ' ';
		}cout << endl;
	}
	*/

	for (int i = 1; i <= N; i++) {
		int count = 0;
		unordered_map<int, int>::iterator iter;
		vector<int> st;
		int is_visited[10001] = { 0 };

		is_visited[i] = 1; count++;
		for (iter = nodes[i]->edge_with.begin(); iter != nodes[i]->edge_with.end(); iter++) {
			st.push_back((*iter).first);
		}
		while (!st.empty()) {
			int cur = st.back();
			st.pop_back();
			if (is_visited[cur] == 0) {
				is_visited[cur] = 1;
				count++;
				for (iter = nodes[cur]->edge_with.begin(); iter != nodes[cur]->edge_with.end(); iter++) {
					st.push_back((*iter).first);
				}
			}
		}
		ans[i] = { count, i };
	}

	sort(ans+1, ans + N+1, cmp);

	/*
	for (int i = 1; i <= N; i++) {
		cout << ans[i].first << ' ';
	}cout << endl;

	for (int i = 1; i <= N; i++) {
		cout << ans[i].second << ' ';
	}cout << endl;
	*/

	//print
	int check = ans[1].first;
	for (int i = 1; i <= N; i++) {
		if (check == ans[i].first) {
			cout << ans[i].second << ' ';
		}
	}

	//system("pause");
	return 0;
}
