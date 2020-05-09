#include <iostream>
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

#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0 ,-1 };

ll N, M, ans;
char m[1000][1000];
int visited[1000][1000];
ll col[1000], row[1000];

int solve(ll y, ll x) {
	ll L = x, R = x, D = y, U = y;

	vector<pll> st;
	st.push_back({ y, x });
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		if (visited[cur.first][cur.second] == 0) {
			visited[cur.first][cur.second] = 1;

			L = min(L, cur.second);
			R = max(R, cur.second);
			U = min(U, cur.first);
			D = max(D, cur.first);

			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
				if (0 <= ny && ny < N &&
					0 <= nx && nx < M) {
					if (m[ny][nx] == '#') {
						st.push_back({ ny, nx });
					}
				}
			}
		}
		else if (visited[cur.first][cur.second] == 2) {
			return -1;
		}
	}

	for (ll j = L; j <= R; j++) {
		ll check = 0;
		for (ll i = U; i <= D; i++) {
			if (m[i][j] == '#') {
				if (check == 0) {
					check = 1;
				}
				if (check == 2) {
					return -1;
				}
			}
			else {
				if (check == 1) {
					check = 2;
				}
			}
		}
	}
	for (ll i = U; i <= D; i++) {
		ll check = 0;
		for (ll j = L; j <= R; j++) {
			if (m[i][j] == '#') {
				if (check == 0) {
					check = 1;
				}
				if (check == 2) {
					return -1;
				}
			}
			else {
				if (check == 1) {
					check = 2;
				}
			}
			m[i][j] = '.';
		}
	}

	for (ll j = L; j <= R; j++) {
		col[j] = 1;
		for (ll i = 0; i < N; i++) {
			visited[i][j] = 2;
		}
	}
	for (ll i = U; i <= D; i++) {
		row[i] = 1;
		for (ll j = 0; j < M; j++) {
			visited[i][j] = 2;
		}
	}

	ans++;

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			if (m[i][j] == '#') {
				if (solve(i, j) == -1) {
					ans = -1;
					break;
				}
			}
		}

		if (ans == -1) {
			break;
		}
	}

	for (ll i = 0; i < N; i++) {
		if (row[i] == 0) {
			for (ll j = 0; j < M; j++) {
				if (visited[i][j] == 0) {
					row[i] = 1;
					break;
				}
			}
			if (row[i] == 0) {
				ans = -1;
				break;
			}
		}
	}
	for (ll j = 0; j < M; j++) {
		if (col[j] == 0) {
			for (ll i = 0; i < N; i++) {
				if (visited[i][j] == 0) {
					col[j] = 1;
					break;
				}
			}
			if (col[j] == 0) {
				ans = -1;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
