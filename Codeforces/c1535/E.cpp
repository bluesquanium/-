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

#define LOG 20

ll Q, ans, temp;
vector<ll> a, c;
ll bl_p[300001][LOG + 1];
ll bl_num[300001];

int main(void) {
	cin >> Q;
	a.resize(Q + 1); c.resize(Q + 1);
	cin >> a[0] >> c[0];
	for (ll j = 0; j < LOG + 1; j++) {
		bl_p[0][j] = -1;
	}

	for (ll i = 1; i <= Q; i++) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll p;
			cin >> p >> a[i] >> c[i];
			bl_p[i][0] = p;
			for (ll j = 1; j < LOG + 1; j++) {
				if (bl_p[i][j - 1] != -1) {
					bl_p[i][j] = bl_p[bl_p[i][j - 1]][j - 1];
				}
				else {
					bl_num[i] = j - 1;
					bl_p[i][j] = -1;
				}
			}
		}
		else {
			ll v, w;
			cin >> v >> w;
			ll numGold = 0, cost = 0;

			while (w) {
				ll idx = v;
				while (1) {
					ll check = 0;
					for (ll j = bl_num[idx]; j >= 0; j--) {
						ll targetIdx = bl_p[idx][j];
						if (targetIdx == -1) {
							continue;
						}
						if (a[targetIdx] > 0) {
							idx = targetIdx;
							check = 1;
							break;
						}
					}

					if (check == 0) {
						break;
					}
				}

				if (a[idx] == 0) {
					break;
				}

				if (w >= a[idx]) {
					numGold += a[idx];
					cost += a[idx] * c[idx];

					w -= a[idx];
					a[idx] = 0;
				}
				else {
					numGold += w;
					cost += w * c[idx];

					a[idx] -= w;
					w = 0;
				}
			}

			cout << numGold << ' ' << cost << '\n';
		}
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
