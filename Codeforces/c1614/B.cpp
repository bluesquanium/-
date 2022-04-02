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
vector<pll> m;
vector<ll> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			ll num;
			cin >> num;
			m[i] = { num, i };
		}
		sort(m.rbegin(), m.rend());

		ans.clear(); ans.resize(N);
		ll cur = 1, sum = 0;
		for (ll i = 0; i < N; i++) {
			sum += m[i].first * abs(cur);
			ans[m[i].second] = cur;
			if (cur > 0) {
				cur *= -1;
			}
			else {
				cur = -cur + 1;
			}
		}
		
		cout << sum * 2 << '\n';
		cout << 0 << ' ';
		for (ll i = 0; i < N; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';

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
