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
using namespace std;

#define PRIME_N 32000000

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

#define MAX_FACTORS 10000000
vector<ll> primeFactors[MAX_FACTORS + 1];
void findPrimeFactors(ll n) {
	for (ll p : primes) {
		for (ll i = p; i < n; i += p) {
			primeFactors[i].push_back(p);
		}
	}
}
