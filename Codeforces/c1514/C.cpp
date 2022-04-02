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

#define PRIME_N 100000

vector<ll> primes;
ll pVisited[PRIME_N + 1];
void findPrime(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (pVisited[i] == 0) {
			pVisited[i] = 2;
			primes.push_back(i);
			for (ll j = i * 2; j <= n; j += i) {
				pVisited[j] = 1;
			}
		}
	}
}

ll N, M, ans, temp;
vector<ll> m;

ll visited[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	findPrime(N);

	ll num = N;
	for (ll i = 0; i < primes.size(); i++) {
		if (num == 1) break;

		ll p = primes[i];
		if (num % p == 0) {
			while (num % p == 0) {
				num /= p;
			}
			for (ll j = p; j < N; j += p) {
				visited[j] = 1;
			}
		}
		else if (num < p * p) {
			ll p = num;
			for (ll j = p; j < N; j += p) {
				visited[j] = 1;
			}
			break;
		}
	}

	num = 1;
	for (ll i = 1; i < N; i++) {
		if (visited[i] == 0) {
			num *= i;
			num %= N;

			if (num == 1) {
				m.clear();
				for (ll j = 1; j <= i; j++) {
					if (visited[j] == 0) {
						m.push_back(j);
					}
				}
			}
		}
	}

	cout << m.size() << '\n';
	for (ll i = 0; i < m.size(); i++) {
		cout << m[i] << ' ';
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
