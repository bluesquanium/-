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

ll T, A, B, Q, ans;
vector<pll> m;

int Gcd(int x, int y) {
	return y ? Gcd(y, x%y) : x;
}

int Lcm(int x, int y) {
	return x * y / Gcd(x, y);
}

ll Gcd(ll x, ll y) {
	return y ? Gcd(y, x%y) : x;
}

ll Lcm(ll x, ll y) {
	return x * y / Gcd(x, y);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> A >> B >> Q;
		m.resize(Q);
		for (ll q = 0; q < Q; q++) {
			ll bigger = max(A, B), smaller = min(A, B);
			ans = 0;
			cin >> m[q].first >> m[q].second;
			ans = m[q].second - m[q].first + 1;

			ll lcm = Lcm(A, B);
			ll num = (m[q].second / lcm - m[q].first / lcm + 1);
			if (num == 1) {
				for (ll i = m[q].first % lcm; i <= m[q].second % lcm && i < bigger; i++) {
					ans--;
				}
			}
			else {
				ans -= (num - 2) * bigger;
				for (ll i = m[q].first % lcm; i < bigger; i++) {
					ans--;
				}
				for (ll i = 0; i <= m[q].second % lcm && i < bigger; i++) {
					ans--;
				}
			}

			cout << ans << ' ';
		}
		cout << '\n';
	}

	return 0;
}
