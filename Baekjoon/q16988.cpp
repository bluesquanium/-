#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pii	pair<int,int>
using namespace std;

#define DIR	4
int dy[DIR] = {-1, 0, 1, 0 };
int dx[DIR] = { 0, 1, 0,-1 };

int N, M, ans;
int m[20][20], is_visited[20][20];

void CalStone(int y1, int x1, int y2, int x2) {
	memset(is_visited, 0, sizeof(int) * 20 * 20);
	vector<pii> start_point;
	
	for (int dir = 0; dir < DIR; dir++) {
		int next_y = y1 + dy[dir], next_x = x1 + dx[dir];
		if (0 <= next_y && next_y < N &&
			0 <= next_x && next_x < M) {
			if (m[next_y][next_x] == 2) {
				start_point.push_back({ next_y, next_x });
			}
		}
		next_y = y2 + dy[dir]; next_x = x2 + dx[dir];
		if (0 <= next_y && next_y < N &&
			0 <= next_x && next_x < M) {
			if (m[next_y][next_x] == 2) {
				start_point.push_back({ next_y, next_x });
			}
		}
	}

	int num_eat = 0;
	while (!start_point.empty()) {
		int count = 0;
		bool cant_eat = false;
		vector<pii> st;
		st.push_back(start_point.back()); start_point.pop_back();

		while (!st.empty()) {
			pii cur = st.back(); st.pop_back();

			if (is_visited[cur.first][cur.second] == 0) {
				is_visited[cur.first][cur.second] = 1;
				count++;

				for (int dir = 0; dir < DIR; dir++) {
					int next_y = cur.first + dy[dir], next_x = cur.second + dx[dir];
					if (0 <= next_y && next_y < N &&
						0 <= next_x && next_x < M) {
						if (m[next_y][next_x] == 2 && is_visited[next_y][next_x] == 0) {
							st.push_back({ next_y, next_x });
						}
						else if (m[next_y][next_x] == 0) {
							cant_eat = true;
							//중간에 break 해버리면 해당 못 먹는 덩어리를 다른 지점에서 시작 시에
							//먹을 수 있는 덩어리로 인식할 수 있다.
							//break; 
						}
					}
				}
			}
		}
		if (!cant_eat) {
			num_eat += count;
		}
	}
	ans = max(ans, num_eat);
	return;
}

void Solve() {
	for (int i = 0; i < N*M-1; i++) {
		if (m[i/M][i%M] != 0) continue;
		for (int j = i+1; j < N*M; j++) {
			if (m[j / M][j%M] != 0) continue;

			m[i/M][i%M] = 1;
			m[j/M][j%M] = 1;
			CalStone(i/M, i%M, j/M, j%M);
			m[i/M][i%M] = 0;
			m[j/M][j%M] = 0;
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++)
			cin >> m[i][j];
	Solve();
	cout << ans;
	return 0;
}
