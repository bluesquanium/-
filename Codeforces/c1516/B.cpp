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
vector< vector<ll> > m_bit;

ll bit[32];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		for (ll i = 0; i < 32; i++) {
			bit[i] = 0;
		}
		ans = 1;
		cin >> N;
		m.clear(); m.resize(N);
		m_bit.clear(); m_bit.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			ll num = m[i];
			ll d = 0;
			while (num) {
				if (num % 2) {
					bit[d]++;
					m_bit[i].push_back(d);
				}
				num /= 2;
				d++;
			}
		}

		for (ll i = 0; i < 32; i++) {
			if ((bit[i] % 2) != 0) {
				ans = 0;
				break;
			}
		}

		if (ans == 0) {
			vector<ll> odds;
			for (ll i = 0; i < 32; i++) {
				if (bit[i] % 2 == 1) {
					odds.push_back(i);
				}
			}

			vector<ll> cur(32, 0);
			ll cnt = 0;
			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < m_bit[i].size(); j++) {
					cur[m_bit[i][j]] = (cur[m_bit[i][j]] + 1) % 2;
				}

				ll check = 1;
				ll oddsCur = 0;
				for (ll i = 0; i < 32; i++) {
					if (oddsCur < odds.size() && i == odds[oddsCur]) {
						if (cur[i] == 0) {
							check = 0;
							break;
						}
						oddsCur++;
					}
					else {
						if (cur[i] == 1) {
							check = 0;
							break;
						}
					}
				}

				if (check) {
					cnt++;
					cur.clear();
					cur.resize(32, 0);
				}
			}

			ans = 1;
			for (ll i = 0; i < 32; i++) {
				if (cur[i] == 1) {
					ans = 0;
					break;
				}
			}
			if (cnt < 3) {
				ans = 0;
			}
		}

		if (ans == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
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
