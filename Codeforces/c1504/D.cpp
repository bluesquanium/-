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
ll dy[4] = { -1, 0, 1, 0 };
ll dx[4] = { 0, 1, 0, -1 };

ll N, M, ans, temp;
ll m[100][100];

vector<pll> op[4];

int main(void) {
	cin >> N;
	for (ll n = 0; n < N * N; n++) {
		for (ll i = 1; i <= 3; i++) {
			vector<pll> temp_v;
			for (ll j = 0; j < op[i].size(); j++) {
				ll isValid = 0;
				for (ll dir = 0; dir < DIR; dir++) {
					ll ny = op[i][j].first + dy[dir];
					ll nx = op[i][j].second + dx[dir];

					if (0 <= ny && ny < N &&
						0 <= nx && nx < N) {
						if (m[ny][nx] == 0) {
							isValid = 1;
							break;
						}
					}
				}

				if (isValid == 1) {
					temp_v.push_back(op[i][j]);
				}
			}
			op[i] = temp_v;
		}

		ll a;
		cin >> a;
		ll color = -1;
		for (ll i = 1; i <= 3; i++) {
			if (i != a) {
				if (op[i].size() == 0) {
					ll cntOpenOthers = 0;
					for (ll j = 1; j <= 3; j++) {
						if (j != i) {
							if (op[j].size() != 0) {
								cntOpenOthers++;
							}
						}
					}

					if (cntOpenOthers == 0) {
						color = i;
					}
					else if (cntOpenOthers == 1) {
						color = i;
					}
					else { // 2
						for (ll j = 1; j <= 3; j++) {
							if (j != i && j != a) {
								color = j;
								break;
							}
						}
					}
				}
				else {
					ll cntOpenOthers = 0;
					for (ll j = 1; j <= 3; j++) {
						if (j != i) {
							if (op[j].size() != 0) {
								cntOpenOthers++;
							}
						}
					}

					if (cntOpenOthers == 0) {
						for (ll j = 1; j <= 3; j++) {
							if (j != i && j != a) {
								color = j;
								break;
							}
						}
					}
					else if (cntOpenOthers == 1) {
						color = i;
					}
					else { // 2
						// impossible
					}
				}
				break;
			}
		}

		ll y, x;

		if (m[0][0] == 0) {
			y = 0;
			x = 0;
			m[0][0] = color;
		}
		else {
			for (ll i = 1; i <= 3; i++) {
				if (i != color) {
					if (op[i].size() != 0) {
						for (ll j = 0; j < op[i].size(); j++) {
							for (ll dir = 0; dir < DIR; dir++) {
								ll ny = op[i][j].first + dy[dir];
								ll nx = op[i][j].second + dx[dir];

								if (0 <= ny && ny < N &&
									0 <= nx && nx < N) {
									if (m[ny][nx] == 0) {
										y = ny;
										x = nx;
										m[ny][nx] = color;

										goto PRINT;
									}
								}
							}
						}
					}
				}
			}
		}

		PRINT: // goto
		cout << color << ' ' << y + 1 << ' ' << x + 1 << '\n';
		op[color].push_back({ y, x });
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
