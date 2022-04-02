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

ll Gcd(ll x, ll y) {
	return y ? Gcd(y, x%y) : x;
}

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

map<ll, ll> findPrimeFactors(ll n) {
	map<ll, ll> factors;
	for (ll p : primes) {
		if (n == 0) break;
		ll cnt = 0;
		while (n % p == 0) {
			cnt++;
			n /= p;
		}

		factors[p] = cnt;
	}
	return factors;
}

map<ll, ll> getTotalFactors(ll a, ll b) {
	map<ll, ll> f1 = findPrimeFactors(a);
	map<ll, ll> f2 = findPrimeFactors(b);
	for (auto iter = f2.begin(); iter != f2.end(); iter++) {
		ll p = (*iter).first, cnt = (*iter).second;
		if (f1.count(p) == 0) {
			f1[p] = cnt;
		}
		else {
			f1[p] += cnt;
		}
	}
	return f1;
}

class Elem {
public:
	ll a, b, c, d;
};

ll N, M, ans, temp;
vector<Elem> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime(PRIME_N);

	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i].a >> m[i].b >> m[i].c >> m[i].d;
		ll gcd = Gcd(m[i].a, m[i].b);
		m[i].a /= gcd;
		m[i].b /= gcd;
		gcd = Gcd(m[i].c, m[i].d);
		m[i].c /= gcd;
		m[i].d /= gcd;
	}

	for (ll i = 0; i < M; i++) {
		map<ll, ll> f1 = getTotalFactors(m[i].a, m[i].b);
		map<ll, ll> f2 = getTotalFactors(m[i].c, m[i].d);
		for (auto iter = f1.begin(); iter != f1.end(); iter++) {
			ll p = (*iter).first, cnt = (*iter).second;
		}
	}

	cout << ans;

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
