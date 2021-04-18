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

ll N, Q, ans, temp;
vector<ll> a;
map<ll, ll> factorMap[200001];
map<ll, vector<ll> > totalFactor;

void totalFactorUpdate(ll prime, ll count) {
	if (totalFactor.count(prime) == 0) {
		vector<ll> tempVector(1);
		totalFactor[prime] = tempVector;
	}

	if (totalFactor[prime].size() <= count) {
		totalFactor[prime].push_back(1);
	}
	else {
		totalFactor[prime][count]++;
	}

	if (totalFactor[prime][count] == N) {
		ans *= prime;
		ans %= MOD;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime(PRIME_N);

	ans = 1;
	cin >> N >> Q;
	a.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
		ll num = a[i];
		for (ll p : primes) {
			if (num < p * p) {
				if (factorMap[i].count(num) == 0) {
					factorMap[i][num] = 1;
				}
				else {
					factorMap[i][num]++;
				}
				totalFactorUpdate(num, factorMap[i][num]);
				break;
			}
			while (num % p == 0) {
				if (factorMap[i].count(p) == 0) {
					factorMap[i][p] = 1;
				}
				else {
					factorMap[i][p]++;
				}

				totalFactorUpdate(p, factorMap[i][p]);

				num /= p;
			}
		}
	}
	for (ll q = 0; q < Q; q++) {
		ll idx, x;
		cin >> idx >> x;
		idx--;
		ll num = x;
		for (ll p : primes) {
			if (num < p * p) {
				if (factorMap[idx].count(num) == 0) {
					factorMap[idx][num] = 1;
				}
				else {
					factorMap[idx][num]++;
				}
				totalFactorUpdate(num, factorMap[idx][num]);
				break;
			}
			while (num % p == 0) {
				if (factorMap[idx].count(p) == 0) {
					factorMap[idx][p] = 1;
				}
				else {
					factorMap[idx][p]++;
				}

				totalFactorUpdate(p, factorMap[idx][p]);

				num /= p;
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
