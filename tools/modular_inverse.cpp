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

#define MOD 998244353

vector<ll> f;
vector<ll> inv, rf;

void updateInverseModular(int N) {
	inv.resize(N + 1); rf.resize(N + 1);
	inv[1] = 1;
	rf[0] = rf[1] = 1;
	
	for(ll i = 2; i <= N; i++) {
		inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
		rf[i] = rf[i-1] * inv[i] % MOD;
	}
}

void updateFactorial(int N) {
	f.resize(N + 1);
	f[0] = f[1] = 1;
	for(ll i = 2; i <= N; i++) {
		f[i] = f[i-1] * i % MOD;
	}
}
