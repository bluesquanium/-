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

ll T, N, K, r, p, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		m.clear(); m.resize(N + 1, 0);
		cin >> r >> p;
		m[r] = p;

		ll cur = 1;
		for (ll i = 0; i < K; i++) {
			if (m[cur] != 0) {
				cur++;
			}

			if (cur == N + 1) {
				cout << "W\n";
			}
			else {
				cout << "T " << cur << '\n';
			}
			cin >> r >> p;
			if (r == -1) {
				return -1;
			}
			m[r] = p;
			cur++;
		}

		ll sum = 0;
		ll toggle = 0;
		for (ll i = 1; i <= N; i++) {
			if (m[i] == 0) {
				sum += 1 + toggle;
				toggle = !toggle;
			}
			else {
				sum += m[i];
			}
		}

		cout << "E " << (sum + 1) / 2 << '\n';
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
