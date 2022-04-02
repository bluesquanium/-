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
vector<ll> m;
ll mem[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		ans = 0;
		for (ll i = 0; i < 50; i++) {
			mem[i] = 0;
		}
		for (ll i = 0; i < N; i++) {
			cin >> m[i];

			ll cur = 1;
			ll j = 0;
			while (m[i]) {
				if (mem[j] == 0 && m[i] % 2 == 1) {
					mem[j] = 1;
					ans += cur;
				}
				m[i] /= 2;
				j++;
				cur *= 2;
			}
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
