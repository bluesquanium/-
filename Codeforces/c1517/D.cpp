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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0, -1 };

ll N, M, K, temp;
vector<ll> m;
ll ver[500][500];
ll hor[500][500];
ll ans[500][500];

ll dist[500][500][10];

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M - 1; j++) {
			cin >> hor[i][j];
		}
	}
	for (ll i = 0; i < N - 1; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> ver[i][j];
		}
	}

	if (K % 2) {
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cout << -1 << ' ';
			}
			cout << '\n';
		}
	}
	else {
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				ll mini = INF;
				if (j - 1 >= 0) {
					mini = min(mini, hor[i][j - 1]);
				}
				if (i - 1 >= 0) {
					mini = min(mini, ver[i - 1][j]);
				}

				if (j < M - 1) {
					mini = min(mini, hor[i][j]);
				}
				if (i < N - 1) {
					mini = min(mini, ver[i][j]);
				}

				for (ll k = 0; k < 10; k++) {
					dist[i][j][k] = mini * (k + 1) * 2;
				}
			}
		}

		for (ll t = 0; t < 10; t++) {
			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < M; j++) {
					for (ll d = 0; d < DIR; d++) {
						ll ny = i + dy[d], nx = j + dx[d];
						if (0 <= ny && ny < N &&
							0 <= nx && nx < M) {
							ll sum;
							if (ny != i) {
								if (ny < i) {
									sum = ver[ny][j];
								}
								else {
									sum = ver[i][j];
								}
							}
							else {
								if (nx < j) {
									sum = hor[i][nx];
								}
								else {
									sum = hor[i][j];
								}
							}
							sum *= 2;

							for (ll k = 1; k < 10; k++) {
								dist[i][j][k] = min(dist[i][j][k], sum + dist[ny][nx][k - 1]);
							}
						}
					}
				}
			}
		}

		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cout << dist[i][j][(K - 1) / 2] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
