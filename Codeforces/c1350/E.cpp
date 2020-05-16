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

long long T, N, M, X, Y, P, ans;
vector<pll> startPoints, nextPoints;

#define DIR 4
ll dy[DIR] = { -1, 0, 1, 0 };
ll dx[DIR] = { 0, 1, 0, -1 };

char colormap[1000][1001]; ll ccnt;
ll colored[1000][1000], visited[1000][1000];
void Coloring(ll startY, ll startX, ll Y, ll X) {
	ll color = ++ccnt;
	ll mc = colormap[startY][startX];
	vector<pll> st;
	st.push_back({ startY, startX });
	colored[startY][startX] = color;
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		for (ll dir = 0; dir < DIR; dir++) {
			ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
			if (0 <= ny && ny < Y &&
				0 <= nx && nx < X) {
				if (colormap[ny][nx] == mc && colored[ny][nx] == 0) {
					colored[ny][nx] = color;
					st.push_back({ ny, nx });

					if (startY != -1) {
						startPoints.push_back({ startY, startX });
						startY = -1;
					}
				}
			}
		}
	}
}


ll dist[1000001];
void WalkColored(ll startY, ll startX, ll Y, ll X) {
	vector<pll> st;
	st.push_back({ startY, startX });
	visited[startY][startX] = 0;
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		ll color = colored[cur.first][cur.second];
		for (ll dir = 0; dir < DIR; dir++) {
			ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
			ll ncolor = colored[ny][nx];
			if (0 <= ny && ny < Y &&
				0 <= nx && nx < X) {
				if (visited[ny][nx] > dist[color]) {
					if (dist[ncolor] == INF && dist[ncolor] > dist[color] + 1) {
						dist[ncolor] = dist[color] + 1;
						nextPoints.push_back({ ny, nx });
					}
					else if (ncolor == color) {
						visited[ny][nx] = dist[ncolor];
						st.push_back({ ny, nx });
					}
				}
			}
		}
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 0; i < 1000001; i++) {
		dist[i] = INF;
	}
	for (ll i = 0; i < 1000; i++) {
		for (ll j = 0; j < 1000; j++) {
			visited[i][j] = INF;
		}
	}

	cin >> N >> M >> T;
	for (ll i = 0; i < N; i++) {
		cin >> colormap[i];
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			if (colored[i][j] == 0) {
				Coloring(i, j, N, M);
			}
		}
	}

	for (ll i = 0; i < startPoints.size(); i++) {
		dist[colored[startPoints[i].first][startPoints[i].second]] = 0;
	}

	ll round = 0;
	while (!startPoints.empty()) {
		for (ll i = 0; i < startPoints.size(); i++) {
			WalkColored(startPoints[i].first, startPoints[i].second, N, M);
		}

		startPoints = nextPoints;
		nextPoints.clear();
		round++;
	}


	for (ll t = 1; t <= T; t++) {
		cin >> Y >> X >> P;
		Y--; X--;
		if (dist[colored[Y][X]] != INF && P - dist[colored[Y][X]] > 0) {
			cout << ((long long)(colormap[Y][X] - '0') + P - (long long)dist[colored[Y][X]]) % 2LL << '\n';
		}
		else {
			cout << colormap[Y][X] << '\n';
		}

	}

	return 0;
}
