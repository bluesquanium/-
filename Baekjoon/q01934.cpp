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

ll T, A, B, ans;
vector<ll> m;

ll Gcd(ll x, ll y) {
	return y ? Gcd(y, x%y) : x;
}

ll Lcm(ll x, ll y) {
	return x * y / Gcd(x, y);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> A >> B;

		cout << Lcm(A, B) << '\n';
	}

	return 0;
}
