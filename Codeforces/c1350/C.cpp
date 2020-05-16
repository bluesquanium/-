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
using namespace std;


#define PRIME_N 200000
vector<ll> primes;
ll visited[PRIME_N + 1];
void findPrime(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (visited[i] == 0) {
			visited[i] = 2;
			primes.push_back(i);
			for (ll j = i * 2; j <= n; j += i) {
				visited[j] = 1;
			}
		}
	}
}

ll N, M, ans;
vector<ll> m;
map<ll, pll> factors;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime(447);

	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		for (ll p = 0; p < primes.size(); p++) {
			ll cnt = 0;
			while (m[i] % primes[p] == 0) {
				m[i] /= primes[p];
				cnt++;
			}

			if (factors.count(primes[p]) == 0) {
				factors[primes[p]] = { cnt, INF };
			}
			else {
				if (cnt < factors[primes[p]].second) {
					factors[primes[p]].second = cnt;
					if (factors[primes[p]].second < factors[primes[p]].first) {
						ll t = factors[primes[p]].second;
						factors[primes[p]].second = factors[primes[p]].first;
						factors[primes[p]].first = t;
					}
				}
			}
		}

		if (factors.count(m[i]) == 0) {
			factors[m[i]] = { 1, INF };
		}
		else {
			factors[m[i]].first++;
		}
	}

	ans = 1;
	for (auto iter = factors.begin(); iter != factors.end(); iter++) {
		ll p = (*iter).first, len = (*iter).second.second;
		if (p > 1) {
			if (p <= 447) {
				for (ll i = 0; i < len; i++) {
					ans *= p;
				}
			}
			else {
				if ((*iter).second.first == N) {
					ans *= p;
				}
				else if ((*iter).second.first == N - 1) {
					ans *= p;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
