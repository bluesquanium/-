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

#define MOD 1000000000

ll N, M, ans, of;
string s;
vector<ll> m[2];
map<ll, ll> pfA, pfB;

#define PRIME_N 40000
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
	ans = 1;
	m[0].resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[0][i];
	}
	cin >> M;
	m[1].resize(M);
	for (int i = 0; i < M; i++) {
		cin >> m[1][i];
	}

	findPrime(40000);

	for (int i = 0; i < N; i++) {
		ll cur = 0;
		while (m[0][i] != 1 && cur != primes.size()) {
			if (m[0][i] % primes[cur] == 0) {
				if (pfA.count(primes[cur])) {
					pfA[primes[cur]]++;
				}
				else {
					pfA[primes[cur]] = 1;
				}
				m[0][i] /= primes[cur];
			}
			else {
				cur++;
			}
		}
		if (m[0][i] != 1) {
			if (pfA.count(m[0][i])) {
				pfA[m[0][i]]++;
			}
			else {
				pfA[m[0][i]] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		ll cur = 0;
		while (m[1][i] != 1 && cur != primes.size()) {
			if (m[1][i] % primes[cur] == 0) {
				if (pfB.count(primes[cur])) {
					pfB[primes[cur]]++;
				}
				else {
					pfB[primes[cur]] = 1;
				}
				m[1][i] /= primes[cur];
			}
			else {
				cur++;
			}
		}
		if (m[1][i] != 1) {
			if (pfB.count(m[1][i])) {
				pfB[m[1][i]]++;
			}
			else {
				pfB[m[1][i]] = 1;
			}
		}
	}

	for (auto iter = pfA.begin(); iter != pfA.end(); iter++) {
		ll num = (*iter).first, cnt = (*iter).second;
		if (pfB.count(num)) {
			ll cnt2 = pfB[num];
			ll len = min(cnt, cnt2);
			for (int i = 0; i < len; i++) {
				if (ans * num >= MOD) {
					of = 1;
				}
				ans = (ans * num) % MOD;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (ans != 0 || of) {
			s.push_back(ans % 10 + '0');
		}
		else {
			break;
		}
		ans /= 10;
	}

	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
	}

	return 0;
}
