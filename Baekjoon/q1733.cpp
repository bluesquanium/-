#include <iostream>
#include <vector>
using namespace std;
#define MAX_N	1000001

int N, a, b,count_v, ret;
vector<int> shirt[MAX_N];
int visited[MAX_N], match[MAX_N], ans[MAX_N];

int Dfs(int cur) {
	if (visited[cur] == count_v) return 0;
	visited[cur] = count_v;
	for (int i : shirt[cur]) {
		if (match[i] == 0 || Dfs(match[i])) {
			match[i] = cur;
			return 1;
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		shirt[i].push_back(a);
		shirt[i].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		count_v++;
		if (Dfs(i)) ret++;
	}

	if (ret != N) cout << "-1\n";
	else {
		for (int i = 1; i < MAX_N; i++) ans[match[i]] = i;
		for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
	}
	
	return 0;
}
