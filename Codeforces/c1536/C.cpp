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
vector<ll> ans;
vector<ll> sums;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		string s;
		cin >> s;
		ans.clear(); ans.resize(N, 0);
		sums.clear(); sums.resize(N, 0);

		if (s[0] == 'D') {
			sums[0] = 1;
		}
		for (ll i = 1; i < N; i++) {
			sums[i] = sums[i - 1];
			if (s[i] == 'D') {
				sums[i]++;
			}
		}

		for (ll term = N; term >= 1; term--) {
			ll size = sums[term - 1];
			ll prev = 0;

			ll cnt = 1;
			for (ll i = 1; i * term <= N; i++) {
				ll idx = i * term - 1;

				if (sums[idx] == prev + size) {
					ans[idx] = max(ans[idx], cnt++);
				}
				prev = prev + size;
			}
		}

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
