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

#define MOD 1000000007

ll T, N, M, ans, temp;
vector<ll> m;

ll mem[10][200001][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 0; i < 10; i++) {
		mem[i][0][i] = 1;
	}
	for (ll d = 0; d <= 9; d++) {
		for (ll i = 1; i <= 200000; i++) {
			for (ll j = 1; j <= 9; j++) {
				mem[d][i][j] = mem[d][i - 1][j - 1];
			}
			mem[d][i][0] += mem[d][i - 1][9];
			mem[d][i][0] %= MOD;
			mem[d][i][1] += mem[d][i - 1][9];
			mem[d][i][1] %= MOD;
		}
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		ll digit[10] = { 0 };
		cin >> N >> M;
		ll num = N;
		while (num) {
			digit[num % 10]++;
			num /= 10;
		}

		for (ll d = 0; d <= 9; d++) {
			for (ll i = 0; i <= 9; i++) {
				ans += digit[d] * mem[d][M][i];
				ans %= MOD;
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
