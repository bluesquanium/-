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

ll Gcd(ll x, ll y) {
	return y ? Gcd(y, x%y) : x;
}

#define PRIME_N 10000000

vector<ll> primes;
ll visited[PRIME_N + 1];
ll minp[PRIME_N + 1];
void findPrime(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (visited[i] == 0) {
			visited[i] = 2;
			primes.push_back(i);
			if (minp[i] == 0) {
				minp[i] = i;
			}
			for (ll j = i * 2; j <= n; j += i) {
				visited[j] = 1;
				if (minp[j] == 0) {
					minp[j] = i;
				}
			}
		}
	}
}

ll N, M;
vector<ll> m;
vector<pll> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	findPrime(PRIME_N);

	cin >> N;
	m.resize(N); ans.resize(N);
	for (ll n = 0; n < N; n++) {
		cin >> m[n];

		ll minPrime = minp[m[n]];
		ans[n].first = 1;
		while (m[n] % minPrime == 0) {
			ans[n].first *= minPrime;
			m[n] /= minPrime;
		}
		if (m[n] == 1) {
			ans[n].first = -1;
			ans[n].second = -1;
		}
		else {
			ans[n].second = m[n];
		}
	}

	for (ll i = 0; i < N; i++) {
		cout << ans[i].first << ' ';
	}
	cout << '\n';
	for (ll i = 0; i < N; i++) {
		cout << ans[i].second << ' ';
	}

	return 0;
}
