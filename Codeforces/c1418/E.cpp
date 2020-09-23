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

ll Combination(ll n, ll r) {
	ll num = 1;
	num = (num * f[n]) % MOD;
	num = (num * rf[r]) % MOD;
	num = (num * rf[n-r]) % MOD;

	return num;
}

ll Factorial(ll n, ll r) {
	ll num = (f[n] * rf[n-r]) % MOD;
	return num;
}

ll N, M, ans, temp;
vector<ll> monsters, msum;
vector<pll> shields;


pll monstersSearch(ll power) {
	ll s = 0, e = N;
	while (s < e) {
		ll mid = (s + e) / 2;
		if (power > monsters[mid]) {
			e = mid;
		}
		else {
			if (s == mid) {
				break;
			}
			s = mid;
		}
	}
	return { s + 1, N - (s + 1) };
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	updateInverseModular(N + 1);
	updateFactorial(N + 1);
	monsters.resize(N);
	msum.resize(N);
	shields.resize(M);
	for (ll i = 0; i < N; i++) {
		cin >> monsters[i];
	}
	for (ll i = 0; i < M; i++) {
		cin >> shields[i].first >> shields[i].second;
	}

	sort(monsters.rbegin(), monsters.rend());
	msum[0] = monsters[0];
	for (ll i = 1; i < N; i++) {
		msum[i] = (msum[i - 1] + monsters[i]) % MOD;
	}

	for (ll q = 0; q < M; q++) {
		ans = 0;
		ll df = shields[q].second, dur = shields[q].first;
		pll ms = monstersSearch(df);
		pll msSum = { msum[ms.first - 1], (msum[N - 1] - msum[ms.first - 1] + MOD) % MOD };
		if (ms.first >= dur) {
			ll big = (msSum.first * (ms.first - dur)) % MOD;
			big = (big * inv[ms.first]) % MOD;
			ll small = (msSum.second * (ms.first + 1 - dur)) % MOD;
			small = (small * inv[ms.first + 1]) % MOD;
			ans = (big + small) % MOD;
		}

		cout << ans << '\n';
	}

	return 0;
}
