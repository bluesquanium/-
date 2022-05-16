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

ll T, R, C, ans, temp;
char m[21][22];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll even[2] = { '+', '-' };
	ll odd[2] = { '|', '.' };
	for (ll i = 0; i < 21; i++) {
		for (ll j = 0; j < 21; j++) {
			if (i % 2 == 0) { // even
				m[i][j] = even[j % 2];
			}
			else { // odd
				m[i][j] = odd[j % 2];
			}
		}
	}
	m[0][0] = m[0][1] = m[1][0] = m[1][1] = '.';

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> R >> C;

		cout << "Case #" << t << ":\n";
		for (ll i = 0; i < R * 2 + 1; i++) {
			for (ll j = 0; j < C * 2 + 1; j++) {
				cout << m[i][j];
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
