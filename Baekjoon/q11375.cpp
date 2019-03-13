#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N	1001
#define MAX_M	1001

int N, M, a, b, ans, count_v;
vector<int> want[MAX_N];
int visited[MAX_N];
int work[MAX_M];

int Dfs(int cur) {
	if (visited[cur] == count_v) {
		return 0;
	}
	visited[cur] = count_v;
	for (int w : want[cur]) {
		if (work[w] == 0 || Dfs(work[w]) ) {
			work[w] = cur;
			return 1;
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		while (a--) {
			cin >> b;
			want[i].push_back(b);
		}
	}

	for (int i = 1; i <= N; i++) {
		count_v++;
		if (Dfs(i)) {
			ans++;
		}
	}

	cout << ans;
	return 0;
}
