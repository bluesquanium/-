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

ll N, M, ans, temp;
vector<ll> m;

ll cal2(ll num) {
	ll ret = 0;
	ll pow2 = 2;
	while (num >= pow2) {
		ret += num / pow2;
		pow2 *= 2;
	}
	return ret;
}

ll cal5(ll num) {
	ll ret = 0;
	ll pow5 = 5;
	while (num >= pow5) {
		ret += num / pow5;
		pow5 *= 5;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;

	ans = min(cal2(N) - cal2(N - M) - cal2(M), cal5(N) - cal5(N - M) - cal5(M));

	cout << ans;

	return 0;
}
