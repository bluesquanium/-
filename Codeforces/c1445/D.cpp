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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define MOD 998244353

vector<ll> f;
vector<ll> inv, rf;

void updateInverseModular(int N) {
	inv.resize(N + 1); rf.resize(N + 1); f.resize(N + 1);
	inv[1] = 1;
	f[0] = f[1] = 1;
	rf[0] = rf[1] = 1;

	for (ll i = 2; i <= N; i++) {
		inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
		rf[i] = rf[i - 1] * inv[i] % MOD;
		f[i] = f[i - 1] * i % MOD;
	}
}


ll Combination(ll n, ll r) {
	ll num = 1;
	num = (num * f[n]) % MOD;
	num = (num * rf[r]) % MOD;
	num = (num * rf[n - r]) % MOD;

	return num;
}

ll N, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	updateInverseModular(300000);

	cin >> N;
	m.resize(2 * N);
	for (ll i = 0; i < 2 * N; i++) {
		cin >> m[i];
	}
	sort(m.rbegin(), m.rend());
	ll sum = 0;
	ll i = 0;
	for (; i < N; i++) {
		sum += m[i];
	}
	for (; i < 2 * N; i++) {
		sum -= m[i];
	}
	sum = sum % MOD;

	cout << (sum * Combination(2 * N, N)) % MOD;

	return 0;
}
