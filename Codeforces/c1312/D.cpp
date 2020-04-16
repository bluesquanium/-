#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
using namespace std;

ll N, M, ans = 1;

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

void updateFactorial(int N) {
	f.resize(N + 1);
	f[0] = f[1] = 1;
	for (ll i = 2; i <= N; i++) {
		f[i] = f[i - 1] * i % MOD;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M;
	
	updateInverseModular(M);
	updateFactorial(M);
	ans = f[M] * rf[N - 1] % MOD * rf[M - N + 1] % MOD;

	ans = (ans * (N - 2)) % MOD;
	for (int i = 0; i < N - 3; i++) {
		ans = (ans * 2) % MOD;
	}

	cout << ans;
	return 0;
}
