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

#define MOD 998244353

ll T, N, M, K, Q, ans, temp;
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M >> K >> Q;
		m.clear(); m.resize(Q);
		for (ll i = 0; i < Q; i++) {
			ll x, y;
			cin >> x >> y;
			m[i].first = x;
			m[i].second = y;
		}

		map<ll, ll> ns, ms;
		ll nCnt = 0, mCnt = 0;
		ll diff = 0;
		for (ll i = Q - 1; i >= 0; i--) {
			ll nn = m[i].first, mm = m[i].second;
			if (nCnt != N && mCnt != M && (ns.count(nn) == 0 || ms.count(mm) == 0)) {
				diff++;
			}
			if (ns.count(nn) == 0) {
				ns[nn] = 1;
				nCnt++;
			}
			if (ms.count(mm) == 0) {
				ms[mm] = 1;
				mCnt++;
			}
		}

		ans = 1;
		for (ll i = 0; i < diff; i++) {
			ans *= K;
			ans %= MOD;
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
