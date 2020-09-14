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

ll N, M, ans = 1, temp, res;
ll visited[100001];

#define PRIME_N 100000

vector<ll> primes, factors;
ll primesVisited[PRIME_N + 1];
void findPrime(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (primesVisited[i] == 0) {
			primesVisited[i] = 2;
			primes.push_back(i);
			for (ll j = i * 2; j <= n; j += i) {
				primesVisited[j] = 1;
			}
		}
	}
}

int main(void) {
	cin >> N;
	findPrime(N);
	ll checkPoint = sqrt(primes.size());
	bool check = false;
	for (ll p = 0; p < primes.size(); p++) {
		cout << "B " << primes[p] << '\n';
		cin >> res;
		ll cnt = 0;
		for (ll i = primes[p]; i <= N; i += primes[p]) {
			cnt += (visited[i] == 0);
			visited[i] = 1;
		}
		if (res != cnt) {
			factors.push_back(primes[p]);
		}

		if (check == false && p % checkPoint == checkPoint - 1) {
			cout << "A 1" << '\n';
			cin >> res;
			cnt = 0;
			for (ll i = 1; i <= N; i++) {
				cnt += (visited[i] == 0);
			}
			if (res != cnt) {
				check = true;
				for (ll i = checkPoint - 1; i >= 0; i--) {
					cout << "A " << primes[p - i] << '\n';
					cin >> res;
					if (res != 0) {
						factors.push_back(primes[p - i]);
						break;
					}
				}
			}
		}
	}
	if (check == false && primes.size() != 0 && (primes.size()-1) % checkPoint != checkPoint - 1) {
		cout << "A 1" << '\n';
		cin >> res;
		ll cnt = 0;
		for (ll i = 1; i <= N; i++) {
			cnt += (visited[i] == 0);
		}
		if (res != cnt) {
			check = true;
			for (ll i = ((primes.size()-1) & checkPoint) - 1; i >= 0; i--) {
				cout << "A " << primes[primes.size() - 1 - i] << '\n';
				cin >> res;
				if (res != 0) {
					factors.push_back(primes[primes.size() - 1 - i]);
					break;
				}
			}
		}
	}


	ans = 1;
	for (ll p : factors) {
		ll num = p;
		while (ans * num * p <= N) {
			cout << "A " << num * p << '\n';
			cin >> res;
			if (res == 0) {
				break;
			}
			num *= p;
		}
		ans *= num;
	}

	cout << "C " << ans << '\n';

	return 0;
}
