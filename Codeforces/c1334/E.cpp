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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
#define MOD 998244353
using namespace std;

ll D, Q, V, U, ans;

vector<ll> primes;
void findPrimeFactors(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			primes.push_back(i);
			while (n != 0 && n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		primes.push_back(n);
	}
}

map< ll, ll > pf[2], gcd;
void findPrimeFactorsByPrimes(ll n, map< ll, ll > & pfs) {
	for (ll i = 0; i < primes.size(); i++) {
		ll cnt = 0;
		while (n != 0 && n % primes[i] == 0) {
			cnt++;

			n /= primes[i];
		}
		if (cnt != 0) {
			pfs[primes[i]] = cnt;
		}
	}
}

vector<ll> inv, rf, f;
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
	cin >> D;
	findPrimeFactors(D);
	updateFactorial(50);
	updateInverseModular(50);

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> U >> V;
		ans = 1;
		pf[0].clear(); pf[1].clear(); gcd.clear();
		findPrimeFactorsByPrimes(U, pf[0]);
		findPrimeFactorsByPrimes(V, pf[1]);
		//find gcd;
		for (auto iter = pf[0].begin(); iter != pf[0].end(); iter++) {
			ll num = (*iter).first;
			if (pf[1].count(num) != 0) {
				gcd[num] = pf[0][num] < pf[1][num] ? pf[0][num] : pf[1][num];
			}
		}
		

		vector<ll> t; ll tcnt;

		// u -> gcd
		t.clear();
		tcnt = 0;
		for (auto iter = pf[0].begin(); iter != pf[0].end(); iter++) {
			ll num = (*iter).first, cnt = (*iter).second;
			if (gcd.count(num) != 0) {
				if (cnt > gcd[num]) {
					t.push_back(cnt - gcd[num]);
					tcnt += cnt - gcd[num];
				}
			}
			else {
				t.push_back(cnt);
				tcnt += cnt;
			}
		}
		ans =  (ans * f[tcnt]) % MOD;
		for (int i = 0; i < t.size(); i++) {
			ans = (ans * rf[t[i]]) % MOD;
		}

		// gcd -> v
		t.clear();
		tcnt = 0;
		for (auto iter = pf[1].begin(); iter != pf[1].end(); iter++) {
			ll num = (*iter).first, cnt = (*iter).second;
			if (gcd.count(num) != 0) {
				if (cnt > gcd[num]) {
					t.push_back(cnt - gcd[num]);
					tcnt += cnt - gcd[num];
				}
			}
			else {
				t.push_back(cnt);
				tcnt += cnt;
			}
		}
		ans = (ans * f[tcnt]) % MOD;
		for (int i = 0; i < t.size(); i++) {
			ans = (ans * rf[t[i]]) % MOD;
		}

		cout << ans << '\n';
	}

	return 0;
}
