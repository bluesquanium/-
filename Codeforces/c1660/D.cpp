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

ll T, N, M, X, Y, ans, tempX, tempY;
vector<ll> m;

ll cal(ll s, ll e) {
	ll cur = 0;
	ll total = 0;
	ll pos = 1;
	for (ll i = s; i < e; i++) {
		if (abs(m[i]) == 2) {
			total++;
		}
		if (m[i] < 0) {
			pos *= -1;
		}
	}
	tempX = N; tempY = 0;

	cur = total;
	if (pos < 0) {
		cur = 0;
		ll temp = total;
		for (ll i = s; i < e; i++) {
			if (abs(m[i]) == 2) {
				temp--;
			}
			if (m[i] < 0) {
				cur = temp;
				tempX = i + 1;
				tempY = N - e;
				break;
			}
		}

		temp = total;
		for (ll i = e - 1; i >= s; i--) {
			if (abs(m[i]) == 2) {
				temp--;
			}
			if (m[i] < 0) {
				if (cur < temp) {
					cur = temp;
					tempX = s;
					tempY = N - i;
				}
				break;
			}
		}
	}
	else {
		tempX = s;
		tempY = N - e;
	}

	return cur;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ans = 0;
		X = N;
		Y = 0;

		ll prev = 0;
		for (ll i = 0; i < N; i++) {
			if (m[i] == 0) {
				ll ret = cal(prev, i);
				prev = i + 1;
				
				if (ret > ans) {
					ans = ret;
					X = tempX;
					Y = tempY;
				}
			}
		}
		ll ret = cal(prev, N);
		if (ret > ans) {
			ans = ret;
			X = tempX;
			Y = tempY;
		}

		cout << X << ' ' << Y << '\n';
	}

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
