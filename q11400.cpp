#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, a, b;
vector<int> edge[100001];
vector< pair<int, int>  > ans;
int is_visited[100001];
int count_v;

int Solve(int cur, bool isRoot, int prev) {
	is_visited[cur] = ++count_v;
	int next_min = is_visited[cur];
	int divided_child = 0;
	for (int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i];
		if (next == prev) {
			continue;
		}
		if (is_visited[next] != 0) {
			next_min = min(next_min, is_visited[next]);
		}
		else {
			divided_child++;
			int temp = Solve(next, false, cur);
			// 이전에 방문한 점일 경우 확인할 필요가 없는게, 이전에 방문한 점이면 visited[next] 값이 더 적을 것이기에 확인 무의미
			if (temp > is_visited[cur]) {
				if (cur < next) {
					ans.push_back({ cur, next });
				}
				else {
					ans.push_back({ next, cur });
				}
			}
			next_min = min(next_min, temp);
		}
	}

	return next_min;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (is_visited[i] == 0) {
			Solve(i, true, -1);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	int prev1 = -1, prev2 = -1;
	for (int i = 0; i < ans.size(); i++) {
		if (prev1 != ans[i].first || prev2 != ans[i].second) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
			prev1 = ans[i].first; prev2 = ans[i].second;
		}
	}

	return 0;
}
