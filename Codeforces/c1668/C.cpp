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
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	ans = LINF;
	for (ll c = 0; c < N; c++) {
		ll cur = 0, cnt = 0;
		for (ll i = c + 1; i < N; i++) {
			ll num = ((cur + m[i] - 1) / m[i]);
			if (num * m[i] == cur) {
				num ++;
			}
			cur = num * m[i];
			cnt += num;
		}
		cur = 0;
		for (ll i = c - 1; i >= 0; i--) {
			ll num = ((cur + m[i] - 1) / m[i]);
			if (num * m[i] == cur) {
				num++;
			}
			cur = num * m[i];
			cnt += num;
		}

		ans = min(ans, cnt);
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
