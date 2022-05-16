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

ll T, N, P, ans, temp;
ll m[1000][100];
ll mm[1000][2];
ll mem[1000][100];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> P;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < P; j++) {
				mem[i][j] = LINF;
			}
		}
		for (ll i = 0; i < N; i++) {
			ll mini = INF, maxi = 0;
			for (ll j = 0; j < P; j++) {
				cin >> m[i][j];
				mini = min(mini, m[i][j]);
				maxi = max(maxi, m[i][j]);
			}
			mm[i][0] = mini;
			mm[i][1] = maxi;

			if (i == 0) {
				for (ll j = 0; j < P; j++) {
					mem[0][j] = mm[i][1] + abs(mm[i][1] - m[i][j]);
				}
			}
		}

		for (ll i = 1; i < N; i++) {
			for (ll j = 0; j < P; j++) {
				for (ll k = 0; k < P; k++) {
					m[i][j]; // end
					m[i-1][k]; // start
					ll cost = -1;
					if (m[i - 1][k] < m[i][j]) {
						cost = abs(m[i - 1][k] - mm[i][0]) + mm[i][1] - mm[i][0] + abs(m[i][j] - mm[i][1]);
					}
					else {
						cost = abs(m[i - 1][k] - mm[i][1]) + mm[i][1] - mm[i][0] + abs(m[i][j] - mm[i][0]);
					}
					mem[i][j] = min(mem[i][j], mem[i - 1][k] + cost);
				}
			}
		}

		ans = LINF;
		for (ll i = 0; i < P; i++) {
			ans = min(ans, mem[N - 1][i]);
		}

		cout << "Case #" << t << ": " << ans << '\n';
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
