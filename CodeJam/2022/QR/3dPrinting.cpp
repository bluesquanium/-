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

ll T, N, M, temp;
ll m[3][4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		for (ll i = 0; i < 3; i++) {
			for (ll j = 0; j < 4; j++) {
				cin >> m[i][j];
			}
		}

		ll ans[4] = { 1000000, 1000000, 1000000, 1000000 };
		ll sum = 0;
		cout << "Case #" << t << ": ";
		for (ll i = 0; i < 4; i++) {
			for (ll j = 0; j < 3; j++) {
				ans[i] = min(ans[i], m[j][i]);
			}
			sum += ans[i];
		}
		if (sum < 1000000) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			sum = 0;
			for (ll i = 0; i < 4; i++) {
				if (ans[i] + sum > 1000000) {
					cout << 1000000 - sum << ' ';
					sum = 1000000;
				}
				else {
					cout << ans[i] << ' ';
					sum += ans[i];
				}
			}
			cout << '\n';
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
