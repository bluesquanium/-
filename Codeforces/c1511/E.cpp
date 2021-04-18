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

#define MOD 998244353

ll N, M, ans, temp;
vector<string> m;
ll mem[300001];
ll t[300001];
ll pow2[300001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	pow2[0] = 1;
	for (ll i = 1; i < 300001; i++) {
		pow2[i] = pow2[i - 1] * 2;
		pow2[i] %= MOD;
	}

	t[0] = t[1] = 1;
	for (ll i = 2; i < 300001; i++) {
		t[i] = t[i - 1] * 2;
		t[i] %= MOD;
	}

	mem[2] = 1;
	for (ll i = 4; i < 300001; i += 2) {
		mem[i] = mem[i - 2] + t[i - 2];
		mem[i] %= MOD;
	}
	mem[3] = 1;
	for (ll i = 5; i < 300001; i += 2) {
		mem[i] = mem[i - 2] + t[i - 2];
		mem[i] %= MOD;
	}
	for (ll i = 3; i < 300001; i++) {
		mem[i] += mem[i - 1] * 2;
		mem[i] %= MOD;
	}


	cin >> N >> M;
	m.resize(N);
	ll totalO = 0;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		for (ll j = 0; j < M; j++) {
			if (m[i][j] == 'o') {
				totalO++;
			}
		}
	}

	ll oStart = 0, oCnt = 0;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			if (m[i][j] == 'o') {
				oStart = 1;
				oCnt++;
			}
			else {
				if (oStart) {
					ans += mem[oCnt] * pow2[totalO - oCnt];
					ans %= MOD;

					oStart = 0;
					oCnt = 0;
				}
			}
		}
		if (oStart != 0) {
			ans += mem[oCnt] * pow2[totalO - oCnt];
			ans %= MOD;

			oStart = 0;
			oCnt = 0;
		}
	}
	for (ll j = 0; j < M; j++) {
		for (ll i = 0; i < N; i++) {
			if (m[i][j] == 'o') {
				oStart = 1;
				oCnt++;
			}
			else {
				if (oStart) {
					ans += mem[oCnt] * pow2[totalO - oCnt];
					ans %= MOD;

					oStart = 0;
					oCnt = 0;
				}
			}
		}
		if (oStart != 0) {
			ans += mem[oCnt] * pow2[totalO - oCnt];
			ans %= MOD;

			oStart = 0;
			oCnt = 0;
		}
	}

	cout << ans;

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
