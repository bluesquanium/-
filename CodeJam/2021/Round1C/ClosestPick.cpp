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

ll T, N, K, temp;
vector<ll> m, ans;

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
		sort(m.begin(), m.end());
		
		ans.clear();
		if (m[0] - 1 >= 0) {
			ans.push_back(m[0] - 1);
		}
		for (ll i = 1; i < N; i++) {
			if (m[i] != m[i - 1]) {
				ans.push_back((m[i] - m[i - 1]) / 2);
				ans.push_back((m[i] - m[i - 1] - 1) - (m[i] - m[i - 1]) / 2);
			}
		}
		ans.push_back(K - m[N - 1]);
		sort(ans.rbegin(), ans.rend());

		double num = 0;
		if (ans.size() >= 1) {
			num += ans[0];
		}
		if (ans.size() >= 2) {
			num += ans[1];
		}

		cout << fixed;
		cout.precision(10);
		cout << "Case #" << t << ": " << num / K << '\n';
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
