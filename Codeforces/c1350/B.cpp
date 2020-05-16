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

#define PRIME_N 100000

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

ll T, N, M, ans;
vector<ll> m;
ll mem[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime(100000);

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		cin >> N;
		m.clear(); m.resize(N + 1);
		for (ll i = 1; i <= N; i++) {
			cin >> m[i];
			mem[i] = 1;
		}
		for (ll i = 1; i <= N; i++) {
			for (ll j = i * 2; j <= N; j += i) {
				if (m[i] < m[j]) {
					mem[j] = max(mem[j], mem[i] + 1);
					ans = max(ans, mem[j]);
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
