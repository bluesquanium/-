#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define MAX 500000

#define MOD 998244353
vector<ll> f;
vector<ll> inv, rf;
void updateInverseModular(int N) {
	inv.resize(N + 1); rf.resize(N + 1);
	inv[1] = 1;
	rf[0] = rf[1] = 1;

	for (ll i = 2; i <= N; i++) {
		inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
		rf[i] = rf[i - 1] * inv[i] % MOD;
	}
}

ll Combination(ll n, ll r) {
	ll num = 1;
	for (ll i = 1; i <= n; i++) {
		num = (num * i) % MOD;
	}
	for (ll i = 1; i <= r; i++) {
		num = (num * inv[i]) % MOD;
	}
	for (ll i = 1; i <= n - r; i++) {
		num = (num * inv[i]) % MOD;
	}

	return num;
}

ll N, K, ans;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	updateInverseModular(MAX);
	cin >> N >> K;

	for (ll i = 1; i <= N; i++) {
		if (N / i >= K) {
			ans = (ans + Combination(N / i - 1, K - 1)) % MOD;
		}
	}

	cout << ans;

	return 0;
}
