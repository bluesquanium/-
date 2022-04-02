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

ll Gcd(ll x, ll y) {
	return y ? Gcd(y, x%y) : x;
}

ll T, N, M, ans, temp;
vector<ll> m, m2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		m2.clear();
		ans = 0;
		ll cnt = N - 1;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] % 2 == 0) {
				ans += cnt--;
			}
			else {
				m2.push_back(m[i]);
			}
		}

		for (ll i = 0; i < m2.size(); i++) {
			for (ll j = i + 1; j < m2.size(); j++) {
				if (Gcd(m2[i], m2[j] * 2) != 1) {
					ans++;
				}
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
