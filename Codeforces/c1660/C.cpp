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

ll mem[2][27]; // 0 : cur, 1 : next

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> s;

		mem[0][26] = 0; mem[1][26] = 1;
		for (ll i = 0; i < 26; i++) {
			mem[0][i] = INF;
			mem[1][i] = INF;
		}
		for (ll i = 0; i < s.size(); i++) {
			for (ll j = 0; j < 27; j++) {
				if (mem[0][j] < INF) {
					mem[1][j] = min(mem[1][j], mem[0][j] + 1);

					if (s[i] - 'a' == j) {
						mem[1][26] = min(mem[1][26], mem[0][j]);
					}

					if (j == 26) {
						mem[1][s[i] - 'a'] = min(mem[1][s[i] - 'a'], mem[0][26]);
					}
				}
			}

			for (ll j = 0; j < 27; j++) {
				mem[0][j] = mem[1][j];
				mem[1][j] = INF;
			}
		}

		ans = mem[0][26];

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
