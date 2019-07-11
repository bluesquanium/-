#include <iostream>
#include <vector>
#include <algorithm>
#define MAX	50
#define DIR	4
#define pii	pair<int,int>
using namespace std;

int dy[DIR] = { 1, 0, -1, 0 };
int dx[DIR] = { 0, 1, 0, -1 };
int N, M, r, ans = 9999;
int m[MAX][MAX], temp_m[MAX][MAX];
vector<pii> v;
int selected[10];

void solve(int s, int cur) {
	if (s < M) {
		for (int i = cur; i < v.size(); i++) {
			selected[s] = i;
			solve(s + 1, i + 1);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp_m[i][j] = m[i][j];
			}
		}

		bool stop = false;
		int step = 0, temp_r = r;
		vector<pii> st;
		for (int i = 0; i < M; i++) {
			st.push_back(v[selected[i]]);
		}
		while (!st.empty()) {
			vector<pii> temp_st;
			while (!st.empty()) {
				pii cur = st.back(); st.pop_back();

				if (temp_m[cur.first][cur.second] != 1) {
					if (temp_m[cur.first][cur.second] == 0) {
						temp_r--;
						if (temp_r == 0) {
							stop = true;
							break;
						}
					}
					temp_m[cur.first][cur.second] = 1;

					for (int dir = 0; dir < DIR; dir++) {
						int ny = cur.first + dy[dir], nx = cur.second + dx[dir];
						if (0 <= ny && ny < N &&
							0 <= nx && nx < N) {
							if (temp_m[ny][nx] != 1) {
								temp_st.push_back({ ny, nx });
							}
						}
					}
				}
			}
			if (stop) {
				break;
			}
			st = temp_st;
			step++;
		}

		if (temp_r == 0) {
			ans = min(ans, step);
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) {
				r++;
			}
			else if (m[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}

	if (r == 0) {
		cout << 0;
		return 0;
	}
	solve(0, 0);

	if (ans == 9999) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
