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

#define PRIME_N 33000

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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	findPrime(PRIME_N);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		ans = 1;
		if (N == 1) {
			ans = 0;
		}
		else {
			ll num = N;
			for (ll p: primes) {
				if (p == 2) {
					continue;
				}

				while (num % p == 0) {
					if (num % (p * p) == 0) {
						num /= (p * p);
					}
					else {
						ans = 0;
						break;
					}
				}
				if (ans == 0) {
					break;
				}
			}
			if (num % 2 != 0) {
				ans = 0;
			}
			else {
				while (num % 2 == 0) {
					num /= 2;
				}

				if (num != 1) {
					ans = 0;
				}
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
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
