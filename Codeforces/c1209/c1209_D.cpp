#include <iostream>
#include <vector>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, K, ans, t1, t2;
vector<int> * m;
vector<pii> g;

void dfs(int index) {
	m[index][0] = 1;
	while (m[index].size() != 1) {
		int cur = m[index].back();
		bool c1 = false, c2 = false;
		m[index].pop_back();
		if (m[g[cur].first][0] == 0) {
			m[g[cur].first][0] = 1;
			c1 = true;
		}
		if (m[g[cur].second][0] == 0) {
			m[g[cur].second][0] = 1;
			c2 = true;
		}

		if (c1 || c2) {
			ans++;
			if (c1) dfs(g[cur].first);
			if (c2) dfs(g[cur].second);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	m = new vector<int> [N];
	g.resize(K);
	for (int i = 0; i < N; i++) m[i].push_back(0);
	for (int i = 0; i < K; i++) {
		cin >> t1 >> t2;
		g[i] = { t1-1, t2-1 };
		m[t1-1].push_back(i);
		m[t2-1].push_back(i);
	}

	for (int i = 0; i < N; i++)
		if (m[i].size() != 1) dfs(i);

	cout << K - ans;

	delete[] m;
	return 0;
}
