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

typedef struct {
	ll x1, y1, x2, y2, x3, y3;
} cmd;

ll T, N, M, temp;
char m[100][101];
vector<cmd> ans;

char conv(char x) {
	if (x == '0') {
		return '1';
	}
	return '0';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		for (ll i = 0; i < N - 2; i++) {
			for (ll j = 0; j < M; j++) {
				if (m[i][j] == '1') {
					cmd t;
					t.y1 = i; t.x1 = j;
					t.y2 = i + 1; t.x2 = j;
					t.y3 = i + 1; t.x3 = j + 1;
					if (j == M - 1) {
						t.x3 = j - 1;
						m[i + 1][j - 1] = conv(m[i + 1][j - 1]);
					}
					else {
						m[i + 1][j + 1] = conv(m[i + 1][j + 1]);
					}
					m[i + 1][j] = conv(m[i + 1][j]);
					m[i][j] = '0';
					ans.push_back(t);
				}
			}
		}
		// i = N - 2, N - 1;
		for (ll j = 0; j < M - 2; j++) {
			if (m[N - 2][j] == '1' || m[N - 1][j] == '1') {
				if (m[N - 2][j] == '1' && m[N - 1][j] == '1') {
					cmd t;
					t.y1 = N - 2; t.x1 = j;
					t.y2 = N - 1; t.x2 = j;
					t.y3 = N - 1; t.x3 = j + 1;
					m[N - 1][j + 1] = conv(m[N - 1][j + 1]);
					ans.push_back(t);
				} 
				else if (m[N - 2][j] == '0' && m[N - 1][j] == '1') {
					cmd t;
					t.y1 = N - 1; t.x1 = j;
					t.y2 = N - 2; t.x2 = j + 1;
					t.y3 = N - 1; t.x3 = j + 1;
					m[N - 2][j + 1] = conv(m[N - 2][j + 1]);
					m[N - 1][j + 1] = conv(m[N - 1][j + 1]);
					ans.push_back(t);
				} 
				else if (m[N - 2][j] == '1' && m[N - 1][j] == '0') {
					cmd t;
					t.y1 = N - 2; t.x1 = j;
					t.y2 = N - 2; t.x2 = j + 1;
					t.y3 = N - 1; t.x3 = j + 1;
					m[N - 2][j + 1] = conv(m[N - 2][j + 1]);
					m[N - 1][j + 1] = conv(m[N - 1][j + 1]);
					ans.push_back(t);
				}
				m[N - 2][j] = '0'; m[N - 1][j] = '0';
			}
		}

		ll cnt1 = 0;
		for (ll i = N - 2; i <= N - 1; i++) {
			for (ll j = M - 2; j <= M - 1; j++) {
				if (m[i][j] == '1') {
					cnt1++;
				}
			}
		}
		if (cnt1 == 4) {
			cmd t;
			t.y1 = N - 2; t.x1 = M - 2;
			t.y2 = N - 2; t.x2 = M - 1;
			t.y3 = N - 1; t.x3 = M - 1;
			ans.push_back(t);

			t.y1 = N - 2; t.x1 = M - 2;
			t.y2 = N - 2; t.x2 = M - 1;
			t.y3 = N - 1; t.x3 = M - 2;
			ans.push_back(t);

			t.y1 = N - 2; t.x1 = M - 2;
			t.y2 = N - 1; t.x2 = M - 2;
			t.y3 = N - 1; t.x3 = M - 1;
			ans.push_back(t);

			t.y1 = N - 2; t.x1 = M - 1;
			t.y2 = N - 1; t.x2 = M - 1;
			t.y3 = N - 1; t.x3 = M - 2;
			ans.push_back(t);
		}
		else if (cnt1 == 3) {
			ll pos[3][2], cur = 0;
			for (ll i = N - 2; i <= N - 1; i++) {
				for (ll j = M - 2; j <= M - 1; j++) {
					if (m[i][j] == '1') {
						pos[cur][0] = i;
						pos[cur][1] = j;
						cur++;
					}
				}
			}
			cmd t;
			t.y1 = pos[0][0]; t.x1 = pos[0][1];
			t.y2 = pos[1][0]; t.x2 = pos[1][1];
			t.y3 = pos[2][0]; t.x3 = pos[2][1];
			ans.push_back(t);
		}
		else if (cnt1 == 2) {
			ll pos1[2][2], pos0[2][2], cur1 = 0, cur0 = 0;
			for (ll i = N - 2; i <= N - 1; i++) {
				for (ll j = M - 2; j <= M - 1; j++) {
					if (m[i][j] == '1') {
						pos1[cur1][0] = i;
						pos1[cur1][1] = j;
						cur1++;
					}
					else {
						pos0[cur0][0] = i;
						pos0[cur0][1] = j;
						cur0++;
					}
				}
			}

			cmd t;
			t.y1 = pos0[0][0]; t.x1 = pos0[0][1];
			t.y2 = pos0[1][0]; t.x2 = pos0[1][1];
			t.y3 = pos1[0][0]; t.x3 = pos1[0][1];
			ans.push_back(t);

			t.y1 = pos0[0][0]; t.x1 = pos0[0][1];
			t.y2 = pos0[1][0]; t.x2 = pos0[1][1];
			t.y3 = pos1[1][0]; t.x3 = pos1[1][1];
			ans.push_back(t);
		}
		else if (cnt1 == 1) {
			ll pos1[2], rpos[2], nearPos[2][2];
			for (ll i = N - 2; i <= N - 1; i++) {
				for (ll j = M - 2; j <= M - 1; j++) {
					if (m[i][j] == '1') {
						pos1[0] = i;
						pos1[1] = j;

						if (i == N - 2) {
							nearPos[0][0] = i + 1;
							nearPos[0][1] = j;
							rpos[0] = i + 1;
						}
						else {
							nearPos[0][0] = i - 1;
							nearPos[0][1] = j;
							rpos[0] = i - 1;
						}
						if (j == M - 2) {
							nearPos[1][0] = i;
							nearPos[1][1] = j + 1;
							rpos[1] = j + 1;
						}
						else {
							nearPos[1][0] = i;
							nearPos[1][1] = j - 1;
							rpos[1] = j - 1;
						}
					}
				}
			}

			cmd t;
			t.y1 = pos1[0]; t.x1 = pos1[1];
			t.y2 = nearPos[0][0]; t.x2 = nearPos[0][1];
			t.y3 = rpos[0]; t.x3 = rpos[1];
			ans.push_back(t);

			t.y1 = pos1[0]; t.x1 = pos1[1];
			t.y2 = nearPos[1][0]; t.x2 = nearPos[1][1];
			t.y3 = rpos[0]; t.x3 = rpos[1];
			ans.push_back(t);

			t.y1 = pos1[0]; t.x1 = pos1[1];
			t.y2 = nearPos[0][0]; t.x2 = nearPos[0][1];
			t.y3 = nearPos[1][0]; t.x3 = nearPos[1][1];
			ans.push_back(t);
		}

		cout << ans.size() << '\n';
		for (ll i = 0; i < ans.size(); i++) {
			cout << ans[i].y1 + 1 << ' ' << ans[i].x1 + 1 << ' ' << ans[i].y2 + 1 << ' ' << ans[i].x2 + 1 << ' ' << ans[i].y3 + 1 << ' ' << ans[i].x3 + 1 << '\n';
		}
	}

	return 0;
}
