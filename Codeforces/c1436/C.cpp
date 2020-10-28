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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, X, P, ans, temp;
vector<ll> bigger, smaller;

void bs(ll mSize, ll x) {
	ll left = 0;
	ll right = mSize;
	while (left < right) {
		ll middle = (left + right) / 2;
		if (middle <= x) {
			left = middle + 1;
			if (middle != x) {
				smaller.push_back(middle);
			}
		}
		else {
			right = middle;
			bigger.push_back(middle);
		}
	}

	return;
}

#define MOD 1000000007

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> X >> P;

	bs(N, P);
	ll ans = 1;
	ll bnum = N - X;
	ll snum = X - 1;
	for (ll i = 0; i < bigger.size(); i++) {
		ans = ans * bnum;
		ans = ans % MOD;
		bnum--;
	}
	for (ll i = 0; i < smaller.size(); i++) {
		ans = ans * snum;
		ans = ans % MOD;
		snum--;
	}

	ll rem = bnum + snum;
	while (rem) {
		ans = ans * rem;
		ans = ans % MOD;
		rem--;
	}

	cout << ans;

	return 0;
}
