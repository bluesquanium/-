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

ll T, N, M, ans, temp;
vector<ll> f, p;
vector<ll> rp[100001];

ll cal(ll s) {
	if (rp[s].size() == 0) {
		ans += f[s];
		return f[s];
	}

	ll mini = INF;
	for (ll i = 0; i < rp[s].size(); i++) {
		mini = min(mini, cal(rp[s][i]));
	}

	ans += max(0LL, f[s] - mini);

	return max(f[s], mini);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		for (ll i = 0; i <= N; i++) {
			rp[i].clear();
		}
		f.clear(); f.resize(N + 1);
		p.clear(); p.resize(N + 1);
		for (ll i = 1; i <= N; i++) {
			cin >> f[i];
		}
		for (ll i = 1; i <= N; i++) {
			cin >> p[i];
			rp[p[i]].push_back(i);
		}

		for (ll i = 1; i <= N; i++) {
			if (p[i] == 0) {
				cal(i);
			}
		}

		cout << "Case #" << t << ": " << ans << '\n';
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
