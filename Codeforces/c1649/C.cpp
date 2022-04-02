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

ll N, M, ans, temp;
vector<ll> y[100001];
vector<ll> x[100001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			ll c;
			cin >> c;
			y[c].push_back(i);
			x[c].push_back(j);
		}
	}

	for (ll c = 1; c <= 100001; c++) {
		sort(y[c].begin(), y[c].end());
		sort(x[c].begin(), x[c].end());

		ll cnum = y[c].size();
		for (ll i = 1; i < cnum; i++) {
			if (y[c][i - 1] != y[c][i]) {
				ans += i * (cnum - i) * abs(y[c][i - 1] - y[c][i]);
			}
		}
		for (ll i = 1; i < cnum; i++) {
			if (x[c][i - 1] != x[c][i]) {
				ans += i * (cnum - i) * abs(x[c][i - 1] - x[c][i]);
			}
		}
	}

	cout << ans;

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
