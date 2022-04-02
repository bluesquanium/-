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

ll T, N, L, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> L;
		m.clear(); m.resize(L);
		for (ll i = 0; i < N; i++) {
			ll num;
			cin >> num;
			for (ll j = 0; j < L; j++) {
				if (num == 0) {
					break;
				}
				if (num % 2) {
					m[j]++;
				}
				num /= 2;
			}
		}

		ans = 0;
		ll num = 1;
		for (ll i = 0; i < L; i++) {
			if (m[i] > N / 2) {
				ans += num;
			}
			num *= 2;
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
