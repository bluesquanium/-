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

#define MAX_Y 250
#define MAX_X 250

#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0 ,-1 };

char mmap[MAX_Y][MAX_X + 1];
ll visited[MAX_Y][MAX_X];

typedef struct {
	ll y; ll x;
	//ll mode;
} StItem;

void ReadMmap(ll N) {
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> mmap[i][j];
		}
	}
}

void ReadMmap(ll N, ll M) {
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> mmap[i][j];
		}
	}
}

ll BfsMmapBasic(ll startY, ll startX, ll Y, ll X) {
	ll o = 0, v = 0;
	ll step = 1;
	vector<StItem> st1;
	st1.push_back(StItem{ startY, startX });
	while (!st1.empty()) {
		vector<StItem> st2;
		while (!st1.empty()) {
			StItem cur = st1.back(); st1.pop_back();
			if (visited[cur.y][cur.x] == 0) {
				visited[cur.y][cur.x] = step;

				if (mmap[cur.y][cur.x] == 'v') {
					v++;
				}
				else if (mmap[cur.y][cur.x] == 'k') {
					o++;
				}

				for (ll dir = 0; dir < DIR; dir++) {
					ll ny = cur.y + dy[dir], nx = cur.x + dx[dir];
					if (0 <= ny && ny < Y &&
						0 <= nx && nx < X) {
						if (visited[ny][nx] == 0 && mmap[ny][nx] != '#') {
							st2.push_back(StItem{ ny, nx });
						}
					}
				}
			}
		}
		st1 = st2;
		step++;
	}

	if (o > v) {
		return o;
	}
	else {
		return -v;
	}
}

ll R, C;
pll ans;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> R >> C;
	for (ll i = 0; i < R; i++) {
		cin >> mmap[i];
	}

	for (ll i = 0; i < R; i++) {
		for (ll j = 0; j < C; j++) {
			if (mmap[i][j] != '#' && visited[i][j] == 0) {
				ll num = BfsMmapBasic(i, j, R, C);
				if (num < 0) {
					ans.second += abs(num);
				}
				else {
					ans.first += num;
				}
			}
		}
	}

	cout << ans.first << ' ' << ans.second;

	return 0;
}
