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

#define MAX_Y 500
#define MAX_X 500
#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0 ,-1 };

char mmap[MAX_Y][MAX_X + 1];
ll visited[MAX_Y][MAX_X];

typedef struct {
	ll y; ll x;
	//ll mode;
} StItem;

ll N, T, R, C, ans;

void ReadMmap(ll N) {
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> mmap[i][j];
		}
	}
}

void PrintMmap() {
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cout << mmap[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

ll BfsMmapBasic(ll startY, ll startX, ll Y, ll X, ll targetY, ll targetX) {
	ll step = 1;
	vector<StItem> st1;
	st1.push_back(StItem{startY, startX});
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
						if (visited[ny][nx] == 0) {
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
