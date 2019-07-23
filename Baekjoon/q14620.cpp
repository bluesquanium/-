#include <iostream>
#include <vector>
#include <algorithm>
#define pii	pair<int,int>
#define MAX	10
#define DIR	4
#define UC	13
using namespace std;

int dy[DIR] = { -1, 0 ,1, 0 };
int dx[DIR] = { 0, 1, 0, -1 };
int uc[UC][2] = { {-2,0}, {-1,-1}, {-1,0}, {-1,1}, {0,-2}, {0,-1}, {0,0}, {0,1}, {0,2}, {1,-1}, {1,0}, {1,1}, {2,0} };

int N, ans = 3000;
int m[MAX][MAX];
int check[MAX][MAX];

void solve(int cur, int sum, int c) { // 1-9, 1-9가 가능한 칸
	if (c < 3) {
		for (int i = cur; i < N*N; i++) {
			int y = i / N, x = i % N;
			if (  !(y == 0 || y == N - 1 ||
					x == 0 || x == N - 1) ) {
				if (check[y][x] == 0) { // 0: 가능한 자리, 1: 불가능한 자리
					//sum 계산
					int p = m[y][x];
					for (int d = 0; d < DIR; d++) {
						p += m[y + dy[d]][x + dx[d]];
					}
					//update 'check'
					vector<pii> ucv;
					for (int j = 0; j < UC; j++) {
						int uc_y = y + uc[j][0], uc_x = x + uc[j][1];
						if (1 <= uc_y && uc_y <= N - 2 &&
							1 <= uc_x && uc_x <= N - 2) {
							if (check[uc_y][uc_x] == 0) {
								check[uc_y][uc_x] = 1;
								ucv.push_back({ uc_y, uc_x });
							}
						}
					}
					solve(i + 1, sum + p, c + 1);
					//check 초기화
					for (int j = 0; j < ucv.size(); j++) {
						int uc_y = ucv[j].first, uc_x = ucv[j].second;
						if (1 <= uc_y && uc_y <= N - 2 &&
							1 <= uc_x && uc_x <= N - 2) {
							check[uc_y][uc_x] = 0;
						}
					}
				}
			}
		}
	}
	else {
		ans = min(ans, sum);
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}

	solve(0, 0, 0);

	cout << ans;

	return 0;
}
