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

ll T, N, M, ans, temp;
vector<ll> m;

#define PRIME_N 33333

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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;

	for (ll t = 1; t <= T; t++) {
		cin >> N;
		ans = 0;
		if (N % 2 == 0) {
			if (N == 2) {
				ans = 1;
			}
			else {
				ans = 2;
			}
		}
		else {
			if (N != 1) {
				if (N == 3) {
					ans = 2;
				}
				else {
					ans = 3;
				}

			}
		}

		cout << ans << '\n';
	}

	return 0;
}
