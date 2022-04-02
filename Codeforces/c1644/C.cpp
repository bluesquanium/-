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

ll T, N, X, ans, temp;
vector<ll> m;
ll mem[5001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> X;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		for (ll i = 0; i <= N; i++) {
			mem[i] = 0;
		}

		ans = 0;
		for (ll k = 1; k <= N; k++) {
			ll sum = 0;
			for (ll i = 0; i < k; i++) {
				sum += m[i];
			}
			mem[k] = sum;
			for (ll i = k; i < N; i++) {
				sum += m[i];
				sum -= m[i - k];
				mem[k] = max(mem[k], sum);
			}
		}

		ans = 0;
		for (ll k = 0; k <= N; k++) {
			for (ll i = 1; i <= N; i++) {
				ans = max(ans, mem[i] + min(k, i) * X);
			}

			cout << ans << ' ';
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
