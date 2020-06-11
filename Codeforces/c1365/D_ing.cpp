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

#define MAX_Y 50
#define MAX_X 50
#define DIR 4
ll dy[DIR] = { -1,0,1,0 };
ll dx[DIR] = { 0,1,0,-1 };

ll T, N, M, ans;
char m[50][51];
vector<pll> start_point, bad_point;

ll visited[MAX_Y][MAX_X];

typedef struct {
	ll y; ll x;
	//ll mode;
} StItem;

ll BfsMmapBasic(ll startY, ll startX, ll Y, ll X, ll targetY, ll targetX) {
	for (ll i = 0; i < Y; i++) {
		for (ll j = 0; j < X; j++) {
			visited[i][j] = 0;
		}
	}

	ll step = 1;
	vector<StItem> st1;
	st1.push_back(StItem{ startY, startX });
	while (!st1.empty()) {
		vector<StItem> st2;
		while (!st1.empty()) {
			StItem cur = st1.back(); st1.pop_back();
			if (visited[cur.y][cur.x] == 0) {
				visited[cur.y][cur.x] = step;
				if (cur.y == targetY && cur.x == targetX) {
					return step;
				}

				for (ll dir = 0; dir < DIR; dir++) {
					ll ny = cur.y + dy[dir], nx = cur.x + dx[dir];
					if (0 <= ny && ny < Y &&
						0 <= nx && nx < X) {
						if (visited[ny][nx] == 0 && m[ny][nx] != '#') {
							st2.push_back(StItem{ ny, nx });
						}
					}
				}
			}
		}
		st1 = st2;
		step++;
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		start_point.clear(); bad_point.clear();
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				if (m[i][j] == 'B') {
					bad_point.push_back({ i, j });
				}
				else if (m[i][j] == 'G') {
					start_point.push_back({ i, j });
				}
			}
		}
		for (ll i = 0; i < bad_point.size(); i++) {
			pll cur = bad_point[i];
			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
				if (0 <= ny && ny < N &&
					0 <= nx && nx < M) {
					m[ny][nx] = '#';
				}
			}
		}

		if (m[N - 1][M - 1] == '#' && start_point.size() != 0) {
			ans = 0;
		}
		else {
			for (ll i = 0; i < start_point.size(); i++) {
				pll cur = start_point[i];
				if (m[cur.first][cur.second] == '#') {
					ans = 0;
					break;
				}
			}
		}

		if (ans) {
			for (ll i = 0; i < start_point.size(); i++) {
				pll cur = start_point[i];
				if (BfsMmapBasic(cur.first, cur.second, N, M, N - 1, M - 1) == -1) {
					ans = 0;
					break;
				}
			}
		}

		if (ans) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
