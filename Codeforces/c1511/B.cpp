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

ll T, A, B, C, ans, temp;
vector<ll> m;

ll calDigits(ll num) {
	ll ret = 0;
	while (num) {
		num /= 10;
		ret++;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ll x = 3, y = 7;
		cin >> A >> B >> C;
		for (ll i = 1; i < C; i++) {
			x *= 10;
			y *= 10;
		}

		for (ll i = 0; i < A - C; i++) {
			ll prev = x;
			while (calDigits(prev) == calDigits(x)) {
				prev = x;
				x *= 3;
			}
		}

		for (ll i = 0; i < B - C; i++) {
			ll prev = y;
			while (calDigits(prev) == calDigits(y)) {
				prev = y;
				y *= 7;
			}
		}

		cout << x << ' ' << y << '\n';
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
