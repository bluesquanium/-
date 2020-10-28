#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, K, ans, temp;
vector<ll> m[71];
ll mem[71][71][71][71]; // y x cnt rem
ll mem2[71][71]; // N rem
ll mem3[71][71]; // rem

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;

	ans = 0;
	for (ll i = 0; i < N; i++) {
		m[i].resize(M);
		for (ll j = 0; j < M; j++) {
			if (j != 0) {
				for (ll c = 1; c <= M / 2; c++) {
					for (ll rem = 0; rem < K; rem++) {
						mem[i][j][c][rem] = mem[i][j - 1][c][rem];
					}
				}
			}

			cin >> m[i][j];
			mem[i][j][1][m[i][j] % K] = max(m[i][j], mem[i][j][1][m[i][j] % K]);
			if (j != 0) {
				for (ll c = 1; c <= M / 2; c++) {
					for (ll rem = 0; rem < K; rem++) {
						if (mem[i][j - 1][c - 1][rem] != 0) {
							ll prev = mem[i][j - 1][c - 1][rem];
							mem[i][j][c][(rem + m[i][j]) % K] = max(mem[i][j][c][(rem + m[i][j]) % K], prev + m[i][j]);
						}
					}
				}
			}
		}
	}

	for (ll i = 0; i < N; i++) {
		for (ll c = 0; c <= M / 2; c++) {
			for (ll rem = 0; rem < K; rem++) {
				mem2[i][rem] = max(mem2[i][rem], mem[i][M - 1][c][rem]);
			}
		}
	}

	for (ll rem = 0; rem < K; rem++) {
		mem3[0][rem] = mem2[0][rem];
	}
	for (ll i = 1; i < N; i++) {
		for (ll rem = 0; rem < K; rem++) {
			mem3[i][rem] = mem3[i - 1][rem];
		}
		for (ll rem = 0; rem < K; rem++) {
			for (ll rem2 = 0; rem2 < K; rem2++) {
				mem3[i][rem] = max(mem3[i][rem], mem2[i][rem]);
				if (mem3[i - 1][rem2] && mem2[i][rem]) {
					mem3[i][(rem2 + rem) % K] = max(mem3[i][(rem2 + rem) % K], mem3[i - 1][rem2] + mem2[i][rem]);
				}
			}
		}
	}

	cout << mem3[N - 1][0];

	return 0;
}
