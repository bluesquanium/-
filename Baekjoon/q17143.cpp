#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#define MAX	100
#define DIR	4
#define pii	pair<int,int>
#define piii	tuple<int,int,int>
using namespace std;

int dy[DIR + 1] = { 0, -1, 1, 0, 0 };
int dx[DIR + 1] = { 0, 0, 0, 1, -1 };
int R, C, M, ans;
int m[MAX][MAX][3], temp_m[MAX][MAX][3]; // s, d, z
int shark[MAX*MAX][5];

void solve(int cur) {
	if (cur < C) {
		//상어 사냥
		for (int i = 0; i < R; i++) {
			if (m[i][cur][2] != 0) {
				//사냥
				ans += m[i][cur][2];
				m[i][cur][0] = 0;
				m[i][cur][1] = 0;
				m[i][cur][2] = 0;
				break;
			}
		}
		//상어 이동
		memset(temp_m, 0, sizeof(int)*MAX*MAX * 3);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (m[i][j][2] != 0) {
					if (m[i][j][1] < 3) { // 상하
						int d = m[i][j][1] == 2 ? 1 : -1; // d:1 아래, d:2 위
						int ny = (i + d * m[i][j][0]);
						if (d == 1) {
							if ((ny / (R-1)) % 2 == 0) {
								ny = ny % (R-1);
							}
							else {
								ny = R - 1 - (ny % (R-1));
								d = -1;
							}
						}
						else {
							if (ny < 0) {
								ny *= -1;
								if ((ny / (R-1)) % 2 == 0) { // ->
									ny = ny % (R-1);
									d = 1;
								}
								else { // <-
									ny = R - 1 - (ny % (R-1));
								}
							}
						}

						if (temp_m[ny][j][1] == 0 || temp_m[ny][j][2] < m[i][j][2]) {
							temp_m[ny][j][0] = m[i][j][0];
							temp_m[ny][j][1] = d == 1 ? 2 : 1;
							temp_m[ny][j][2] = m[i][j][2];
						}
					}
					else { // 좌우
						int d = m[i][j][1] == 3 ? 1 : -1;
						int nx = (j + d * m[i][j][0]);
						if (d == 1) {
							if ((nx / (C-1)) % 2 == 0) { // ->
								nx = nx % (C-1);
							}
							else { // <-
								nx = C - 1 - (nx % (C-1));
								d = -1;
							}
						}
						else {
							if (nx < 0) {
								nx *= -1;
								if ((nx / (C-1)) % 2 == 0) { // ->
									nx = nx % (C-1);
									d = 1;
								}
								else { // <-
									nx = C - 1 - (nx % (C-1));
								}
							}
						}

						if (temp_m[i][nx][1] == 0 || temp_m[i][nx][2] < m[i][j][2]) {
							temp_m[i][nx][0] = m[i][j][0];
							temp_m[i][nx][1] = d == 1 ? 3 : 4;
							temp_m[i][nx][2] = m[i][j][2];
						}
					}
				}
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				m[i][j][0] = temp_m[i][j][0];
				m[i][j][1] = temp_m[i][j][1];
				m[i][j][2] = temp_m[i][j][2];
				//cout << m[i][j][2] << ' ';
			}//cout << '\n';
		}//cout << '\n';

		solve(cur + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> shark[i][j];
		}
		shark[i][0]--; shark[i][1]--;
		int y = shark[i][0], x = shark[i][1];
		if (m[y][x][1] == 0 || m[y][x][2] < shark[i][4]) {
			m[y][x][0] = shark[i][2];
			m[y][x][1] = shark[i][3];
			m[y][x][2] = shark[i][4];
		}
	}

	solve(0);
	cout << ans;
	return 0;
}
