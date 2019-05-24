#include <iostream>
#include <vector>
#include <algorithm>
#define pii	pair<int,int>
#define x_archors(X)	archors[X]
using namespace std;

int N, M, D, ans;
int m[15][15];
vector<int> archors;

void Dfs(int count, int cur) {
	if (count < 3) {
		for (int i = cur; i < M; i++) {
			archors.push_back(i);
			Dfs(count + 1, i + 1);
			archors.pop_back();
		}
	}
	else {
		int temp_m[15][15];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp_m[i][j] = m[i][j];
			}
		}
		int result = 0;
		int y_archors = N;
		while (y_archors > 0) {
			pii min_d[3] = { {-100, -100}, {-100, -100}, {-100, -100} };
			for (int i = 0; i < y_archors; i++) {
				for (int j = 0; j < M; j++) {
					if (temp_m[i][j] == 1) {
						for(int arc = 0; arc < 3; arc++) {
							int dist_new  = abs(y_archors - i) + abs(x_archors(arc) - j),
								dist_prev = abs(y_archors - min_d[arc].first) + abs(x_archors(arc) - min_d[arc].second);
							if (dist_new <= D) {
								if ((dist_new < dist_prev) || (dist_new == dist_prev && j < min_d[arc].second)) {
									min_d[arc] = { i,j };
								}
							}
						}
					}
				}
			}

			for (int arc = 0; arc < 3; arc++) {
				if (min_d[arc].first != -100 && temp_m[min_d[arc].first][min_d[arc].second] == 1) {
					temp_m[min_d[arc].first][min_d[arc].second] = 0;
					result++;
				}
			}

			y_archors--;
		}

		ans = max(ans, result);
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}

	Dfs(0, 0);

	cout << ans;

	return 0;
}
