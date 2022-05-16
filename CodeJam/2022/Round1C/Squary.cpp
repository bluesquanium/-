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

ll T, N, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		ll sum = 0, sumSq = 0;
		for (ll i = 0; i < N; i++) {
			sum += m[i];
			sumSq += m[i] * m[i];
		}

		if (sum == 0) {
			if (sumSq == 0) {
				ans = 1;
			}
			else {
				cout << "Case #" << t << ": " << "IMPOSSIBLE" << '\n';
				continue;
			}
		}
		else {
			ans = (sumSq - sum * sum) / (2 * sum);
		}

		sum = ans; sumSq = ans * ans;
		for (ll i = 0; i < N; i++) {
			sum += m[i];
			sumSq += m[i] * m[i];
		}

		if (sum == sumSq) {
			cout << "Case #" << t << ": " << ans << '\n';
		}
		else {
			cout << "Case #" << t << ": " << "IMPOSSIBLE" << '\n';
		}
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
