#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX	1001
#define pii	pair<int,int>
#define DIR	4
using namespace std;

int dy[DIR] = { -1, 0, 1, 0 };
int dx[DIR] = {  0, 1, 0,-1 };

int R, C, T, ans = 2; // 공기청정기 -1*2 때문에 2 저장
int m[MAX][MAX], temp_m[MAX][MAX];
int cleaner[2][2];

void solve(int cur_t, int T) {
	if (cur_t < T) {
		memset(temp_m, 0, sizeof(int)*MAX*MAX);
		temp_m[cleaner[0][0]][cleaner[0][1]] = -1;
		temp_m[cleaner[1][0]][cleaner[1][1]] = -1;

		//미세먼지 확산
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (m[i][j] != 0 && m[i][j] != -1) {
					int c = 0;
					for (int dir = 0; dir < DIR; dir++) {
						int ny = i + dy[dir], nx = j + dx[dir];
						if (0 <= ny && ny < R &&
							0 <= nx && nx < C) {
							if (temp_m[ny][nx] != -1) {
								temp_m[ny][nx] += m[i][j] / 5;
								c++;
							}
						}
					}
					temp_m[i][j] += m[i][j] - (m[i][j] / 5) * c;
				}
			}
		}

		//공기청정기 작동
		//위쪽 1 -> 0 -> 3 -> 2
		int dir = 1, prev = temp_m[cleaner[0][0]][cleaner[0][1] + 1];
		int ny = cleaner[0][0] + dy[dir], nx = cleaner[0][1] + dx[dir];
		temp_m[cleaner[0][0]][cleaner[0][1] + 1] = 0;
		do {
			while (0 <= ny + dy[dir] && ny + dy[dir] < R &&
				   0 <= nx + dx[dir] && nx + dx[dir] < C &&
				   temp_m[ny + dy[dir]][nx + dx[dir]] != -1) {
				ny += dy[dir]; nx += dx[dir];
				int temp = temp_m[ny][nx];
				temp_m[ny][nx] = prev;
				prev = temp;
			}
			dir = (DIR + dir - 1) % DIR; // 반시계
		} while (dir != 1);
		//아래쪽 1 -> 2 -> 3 -> 0
		dir = 1; prev = temp_m[cleaner[1][0]][cleaner[1][1] + 1];
		ny = cleaner[1][0] + dy[dir]; nx = cleaner[1][1] + dx[dir];
		temp_m[cleaner[1][0]][cleaner[1][1] + 1] = 0;
		do {
			while (0 <= ny + dy[dir] && ny + dy[dir] < R &&
				   0 <= nx + dx[dir] && nx + dx[dir] < C &&
				   temp_m[ny + dy[dir]][nx + dx[dir]] != -1) {
				ny += dy[dir]; nx += dx[dir];
				int temp = temp_m[ny][nx];
				temp_m[ny][nx] = prev;
				prev = temp;
			}
			dir = (dir + 1) % DIR; // 시계
		} while (dir != 1);

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				m[i][j] = temp_m[i][j];
			}
		}

		solve(cur_t + 1, T);
	}
	else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				ans += m[i][j];
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> m[i][j];
			if (m[i][j] == -1) { // 공기청정기 위치 저장
				if (cleaner[0][0] == 0) {
					cleaner[0][0] = i;
					cleaner[0][1] = j;
				}
				else {
					cleaner[1][0] = i;
					cleaner[1][1] = j;
				}
			}
		}
	}
	solve(0, T);
	cout << ans;
	return 0;
}
