#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans;
ll m[31][31];
ll dist[100][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		for (ll i = 0; i < 100; i++) {
			dist[i][0] = dist[i][1] = 0;
		}
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cin >> m[i][j];
				ll mini = min(i + j, N + M - 2 - i - j);
				dist[mini][m[i][j]]++;
			}
		}

		for (ll i = 0; i < 100; i++) {
			if ((N + M - 2) % 2 == 0 && i == (N + M - 2) / 2) {
				continue;
			}
			if (dist[i][0] != 0 && dist[i][1] != 0) {
				ans += min(dist[i][0], dist[i][1]);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
