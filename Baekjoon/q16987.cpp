#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, b, count_left, ans;
vector< pair<int, int> > eggs;

void Dfs(int cur) {
	if (cur == N) {
		ans = max(ans, N - count_left);
		return;
	}
	if (eggs[cur].first <= 0) {
		Dfs(cur + 1);
		return;
	}

	int nothing_used = true;
	for (int i = 0; i < N; i++) {
		if (i == cur || eggs[i].first <= 0) continue;
		nothing_used = false;

		bool c1 = false, c2 = false;
		eggs[cur].first -= eggs[i].second;
		eggs[i].first -= eggs[cur].second;
		if (eggs[cur].first <= 0) {
			c1 = true;
			count_left--;
		}
		if (eggs[i].first <= 0) {
			c2 = true;
			count_left--;
		}
		Dfs(cur + 1);
		if (c1 == true) count_left++;
		if (c2 == true) count_left++;
		eggs[cur].first += eggs[i].second;
		eggs[i].first += eggs[cur].second;
	}

	if (nothing_used) Dfs(cur + 1);

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	count_left = N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		eggs.push_back({ a,b });
	}

	Dfs(0);

	cout << ans;
	return 0;
}
