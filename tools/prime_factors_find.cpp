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

vector<ll> pfs;
void findPrimeFactors(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			pfs.push_back(i);
			while (n != 0 && n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		pfs.push_back(n);
	}
}
