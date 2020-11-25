#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N	201
#define MAX_M	201

int N, M, a, b, ans;
vector<int> cow[MAX_N];
bool visited[MAX_N];
int space[MAX_M];

// 기본적인 이분탐색 방법 
int Dfs(int cur) {
	if (visited[cur]) {
		return 0;
	}
	visited[cur] = 1;

	for (int i : cow[cur]) {
		if (space[i] == 0 || Dfs(space[i])) {
			space[i] = cur;
			return 1;
		}
	}

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	//cow = new vector<int>[M+1]; // 0은 더미
	memset(space, 0, sizeof(int)*(M + 1));
	for (int i = 1; i <= N; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			cow[i].push_back(b);
		}
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(bool)*(N + 1));
		if (Dfs(i)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
