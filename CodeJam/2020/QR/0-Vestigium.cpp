#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll T, N, K, R, C;
ll m[101][101];
ll row[100][101];
ll col[100][101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		K = R = C = 0;
		for (int i = 0; i < N; i++) {
			memset(row[i], 0, sizeof(ll) * 101);
			memset(col[i], 0, sizeof(ll) * 101);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> m[i][j];
				if (i == j) {
					K += m[i][j];
				}
				row[i][m[i][j]]++;
				col[j][m[i][j]]++;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (row[i][j] != 1) {
					R++;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (col[i][j] != 1) {
					C++;
					break;
				}
			}
		}

		cout << "Case #" << t << ": " << K << ' ' << R << ' ' << C << '\n';
	}

	return 0;
}
