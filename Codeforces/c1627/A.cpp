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

ll T, N, M, R, C, ans, temp;
char m[50][50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C;
		R--; C--;
		ans = -1;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cin >> m[i][j];
				if (m[i][j] == 'B') {
					ans =  0;
				}
			}
		}
		if (m[R][C] != 'B') {
			for (ll i = 0; i < M; i++) {
				if (m[R][i] == 'B') {
					ans = 1;
				}
			}
			for (ll i = 0; i < N; i++) {
				if (m[i][C] == 'B') {
					ans = 1;
				}
			}

			if (ans == 0) {
				ans = 2;
			}
		}

		cout << ans << '\n';
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
