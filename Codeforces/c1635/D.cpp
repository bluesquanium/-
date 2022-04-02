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

#define MOD 1000000007

const ll maxi = 1000000000;
ll N, P, ans, temp;
vector<ll> m, a;
map<ll, ll> mem;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> P;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());

	a.push_back(m[0]);
	mem[m[0]] = 1;

	for (ll i = 1; i < N; i++) {
		ll dup = 0;
		ll num = m[i];
		while (num) {
			if (mem.count(num) == 1) {
				dup = 1;
				break;
			}

			if (num % 2 == 0) {
				if (num % 4 == 0) {
					num /= 4;
				}
				else {
					break;
				}
			}
			else {
				num = (num - 1) / 2;
			}
		}

		if (dup == 0) {
			a.push_back(m[i]);
			mem[m[i]] = 1;
		}
	}

	ans = 0;

	ll aCur = 0;
	ll tp[4] = { 0, 0, 0, 0 };
	ll num = 1;
	for (ll p = 0; p <= P; p++) {
		ll tmp[4] = { tp[0], tp[1], tp[2], tp[3] };

		tp[0] = tmp[3];
		tp[3] = tmp[0];

		tp[1] = tmp[3] + tmp[1] + tmp[2];
		tp[1] = tp[1] % MOD;
		tp[2] = tmp[1];

		ans += tmp[3] * 2;
		ans = ans % MOD;
		ans += tmp[1];
		ans = ans % MOD;
		ans += tmp[2];
		ans = ans % MOD;

		while (aCur < a.size() && a[aCur] <= num) {
			if (num == a[aCur]) {
				tp[0]++;
			}
			else {
				tp[1]++;
			}

			ans++;
			ans = ans % MOD;

			aCur++;
		}

		if (num < MOD) {
			num *= 2;
		}
	}

	if (tp[0]) {
		ans -= tp[0];
	}

	ans = (ans + MOD) % MOD;

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
