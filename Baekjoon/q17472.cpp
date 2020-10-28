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

#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0, -1 };

ll N, M, ans, temp;
ll m[10][10];
ll visited[10][10];
ll edges[7][7];

ll ccnt = 0;

void BuildBridge(ll y, ll x) {
	ll color = m[y][x];
	for (ll dir = 0; dir < DIR; dir++) {
		ll cnt = 0;
		ll ny = y, nx = x;
		while (1) {
			ny = ny + dy[dir]; nx = nx + dx[dir];
			if (0 <= ny && ny < N &&
				0 <= nx && nx < M) {
				if (m[ny][nx] != 0) {
					if (m[ny][nx] != color && cnt >= 2) {
						ll color2 = m[ny][nx];
						edges[color][color2] = min(edges[color][color2], cnt);
						edges[color2][color] = min(edges[color2][color], cnt);
					}
					break;
				}
				cnt++;
			}
			else {
				break;
			}
		}
	}
}

void Coloring(ll y, ll x, ll color) {
	m[y][x] = color;

	vector<pll> st;
	st.push_back({ y, x });
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		if (visited[cur.first][cur.second] == 0) {
			visited[cur.first][cur.second] = 1;
			m[cur.first][cur.second] = color;

			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
				if (0 <= ny && ny < N &&
					0 <= nx && nx < M) {
					if (m[ny][nx] == -1) {
						st.push_back({ ny, nx });
					}
				}
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 1; i <= 6; i++) {
		for (ll j = 1; j <= 6; j++) {
			edges[i][j] = LINF;
		}
	}

	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> m[i][j];
			if (m[i][j] == 1) {
				m[i][j] = -1;
			}
		}
	}

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			if (m[i][j] == -1) {
				Coloring(i, j, ++ccnt);
			}
		}
	}

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			if (m[i][j] != 0) {
				BuildBridge(i, j);
			}
		}
	}

	ll check[7] = { 0 };
	check[1] = 1;
	priority_queue< pll, vector<pll>, greater<pll> > pq; // dist, islandIdx
	for (ll i = 1; i <= 6; i++) {
		if (edges[1][i] != LINF) {
			pq.push({ edges[1][i], i });
		}
	}

	while (!pq.empty()) {
		pll cur = pq.top(); pq.pop();

		if (check[cur.second] == 0) {
			check[cur.second] = 1;
			ans += cur.first;
			for (ll i = 1; i <= 6; i++) {
				if (edges[cur.second][i] != LINF) {
					pq.push({ edges[cur.second][i], i });
				}
			}
		}
	}

	ll allVisited = 1;
	for (ll i = 1; i <= ccnt; i++) {
		if (check[i] == 0) {
			allVisited = 0;
			break;
		}
	}

	if (allVisited == 0) {
		cout << "-1";
	}
	else {
		cout << ans;
	}

	return 0;
}
