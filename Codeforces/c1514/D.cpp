#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <random>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll N, Q, ans, temp;
vector<ll> m;
vector<ll> numIdx[300001];
vector<pll> queries;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N);
	queries.resize(Q);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		numIdx[m[i]].push_back(i);
	}

	mt19937 rng = mt19937(time(0));

	for (ll q = 0; q < Q; q++) {
		ans = 1;
		map<ll, ll> picked;
		ll l, r;
		cin >> l >> r;
		l--; r--;
		for (ll i = 0; i < 50; i++) {
			ll idx = uniform_int_distribution<int>(l, r)(rng);
			ll val = m[idx];
			ll num = upper_bound(numIdx[val].begin(), numIdx[val].end(), r) - lower_bound(numIdx[val].begin(), numIdx[val].end(), l);
			ll numElem = (r - l) + 1;
			ans = max(ans, numElem - ((numElem - num) * 2));
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
