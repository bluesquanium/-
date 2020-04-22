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

ll N, ans;

#define PRIME_N 4000
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
	cin >> N;
	findPrime(4000);
	ll cur = 0;
	while (N != 1 && cur != primes.size()) {
		if (N % primes[cur] == 0) {
			cout << primes[cur] << '\n';
			N /= primes[cur];
		}
		else {
			cur++;
		}
	}

	if (N != 1) {
		cout << N;
	}

	return 0;
}
