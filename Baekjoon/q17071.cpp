#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX	500000

int C, B, ans;
bool visited[MAX + 1][2];
vector<int> b_pos;

void Bfs() {
	ans++;
	visited[B][0] = 1;
	b_pos.push_back(B);
	C = C + ans;
	while (C <= MAX) {
		vector<int> temp_b_pos;
		if (visited[C][ans%2]) return;
		while (!b_pos.empty()) {
			int cur = b_pos.back(); b_pos.pop_back();

			if (cur - 1 == C || cur + 1 == C || cur * 2 == C) {
				return;
			}

			if (0 <= cur - 1) {
				if (visited[cur - 1][ans%2] == 0) {
					temp_b_pos.push_back(cur - 1);
					visited[cur - 1][ans%2] = 1;
				}
			}
			if (cur + 1 <= MAX) {
				if (visited[cur + 1][ans%2] == 0) {
					temp_b_pos.push_back(cur + 1);
					visited[cur + 1][ans%2] = 1;
				}
			}
			if (cur * 2 <= MAX) {
				if (visited[cur * 2][ans%2] == 0) {
					temp_b_pos.push_back(cur * 2);
					visited[cur * 2][ans%2] = 1;
				}
			}
		}
		b_pos = temp_b_pos;
		ans++;
		C = C + ans;
	}
	ans = -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> B >> C;

	if (C == B) {
		cout << 0;
		return 0;
	}
	Bfs();
	cout << ans;
	return 0;
}
