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

ll N, ans, temp;
ll m[100][100];

ll visited[100][100];
vector< vector<pll> > islands;
ll iCnt;

void doPainting(ll y, ll x) {
	ll iID = iCnt++;
	vector<pll> t;
	islands.push_back(t);

	vector<pll> st;
	st.push_back({ y, x });

	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();

		if (visited[cur.first][cur.second] == 0) {
			visited[cur.first][cur.second] = 1;
			islands[iID].push_back({ cur });

			for (ll dir = 0; dir < DIR; dir++) {
				ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
				if (0 <= ny && ny < N &&
					0 <= nx && nx < N) {
					if (m[ny][nx] == 1 && visited[ny][nx] == 0) {
						st.push_back({ ny, nx });
					}
				}
			}
		}
	}
}

void findIslands() {
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (m[i][j] == 1 && visited[i][j] == 0) {
				doPainting(i, j);
			}
		}
	}
}

ll minDistance(vector<pll> a, vector<pll> b) {
	ll ret = LINF;
	
	for (ll i = 0; i < a.size(); i++) {
		for (ll j = 0; j < b.size(); j++) {
			ret = min(ret, abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second));
		}
	}

	return ret;
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

	findIslands();

	ans = INF;
	for (ll i = 0; i < islands.size(); i++) {
		for (ll j = 0; j < islands.size(); j++) {
			if (i == j) continue;

			ans = min(ans, minDistance(islands[i], islands[j]));
		}
	}

	cout << ans - 1;

	return 0;
}
