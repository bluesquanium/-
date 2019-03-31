#include <iostream>
#include <vector>
#include <algorithm>
#define MAX	200000
#define pii	pair<int,int>
using namespace std;

int N, M, a, b;
bool ans = true;
vector<int> edge[MAX + 1];
vector<pii> cmd;
int visited[MAX + 1];

void Dfs(int cur, int toggle) {
	if (ans == false) return;
	if (visited[cur] == 0) {
		visited[cur] = toggle;

		for (int i = 0; i < edge[cur].size(); i++) {
			Dfs(edge[cur][i], -toggle);
		}
	}
	else if (visited[cur] != toggle) {
		ans = false;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cmd.push_back({ a,b });
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	Dfs(1, 1);

	if (ans == false) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		for (int i = 0; i < M; i++) {
			if (visited[cmd[i].first] == 1) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
	}
	
	return 0;
}
