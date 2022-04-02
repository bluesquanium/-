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

#define MAXBIT 100001
class Bit {
public:
	ll tree[MAXBIT];

	void init() {
		for (ll i = 0; i < MAXBIT; i++) tree[i] = 0;
	}

	void add(ll x, ll v) {
		for (ll i = x; i < MAXBIT; i += i & -i) {
			tree[i] += v;
		}
	}

	ll query(ll x) {
		ll ret = 0;
		for (ll i = x; i; i -= i & -i) {
			ret += tree[i];
		}
		return ret;
	}
} bit;

ll N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	m.resize(N);

	bit.init();
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		bit.add(i + 1, m[i]);
	}
	for (ll i = 0; i < M; i++) {
		ll l, r;
		cin >> l >> r;
		cout << bit.query(r) - bit.query(l - 1) << '\n';
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
