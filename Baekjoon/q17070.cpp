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

#define DIR 3
ll dy[DIR] = {0, 1, 1};
ll dx[DIR] = {1, 0, 1};

ll N, M, ans, temp;
ll m[16][16];

void solve(ll prevType, ll y, ll x) {
	if (y == N - 1 && x == N - 1) {
		ans++;
		return;
	}

	for (ll dir = 0; dir < DIR; dir++) {
		if ((prevType == 0 && dir == 1) ||
			(prevType == 1 && dir == 0)) {
			continue;
		}
		ll ny = y + dy[dir], nx = x + dx[dir];
		if (ny < N && nx < N && m[ny][nx] == 0) {
			if(dir == 2) { // diagonal
				if (m[y + dy[0]][x + dx[0]] || m[y + dy[1]][x + dx[1]]) {
					continue;
				}
			}
			solve(dir, ny, nx);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}

	solve(0, 0, 1);

	cout << ans;

	return 0;
}
