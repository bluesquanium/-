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

typedef struct {
	ll y; ll x;
	//ll mode;
} StItem;


ll R, C, ans;
pll dest, start;
vector<StItem> water1;
char m[250][251];
ll visited[250][251];

ll BfsMmapBasic(ll startY, ll startX, ll Y, ll X, ll targetY, ll targetX) {
	ll step = 0;
	vector<StItem> st1;
	st1.push_back(StItem{ startY, startX });
	while (!st1.empty()) {
		vector<StItem> st2, water2;

		while (!water1.empty()) {
			StItem cur = water1.back(); water1.pop_back();

			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.y + dy[dir], nx = cur.x + dx[dir];
				if (0 <= ny && ny < Y &&
					0 <= nx && nx < X) {
					if (m[ny][nx] == '.') {
						m[ny][nx] = '*';
						water2.push_back(StItem{ ny, nx });
					}
				}
			}
		}
		water1 = water2;

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
						if (m[ny][nx] != '*' && visited[ny][nx] == 0) {
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
	cin >> R >> C;
	for (ll i = 0; i < R; i++) {
		cin >> m[i];
		for (ll j = 0; j < C; j++) {
			if (m[i][j] == '*') {
				water1.push_back({ i,j });
			}
			if (m[i][j] == 'X') {
				m[i][j] = '*';
			}
			else if (m[i][j] == 'S') {
				m[i][j] = '*';
				start = { i, j };
			}
			else if (m[i][j] == 'D') {
				dest = { i, j };
			}
		}
	}

	ans = BfsMmapBasic(start.first, start.second, R, C, dest.first, dest.second);
	if (ans == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << ans;
	}

	return 0;
}
