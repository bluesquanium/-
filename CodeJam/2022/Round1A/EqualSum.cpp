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

ll T, N, M, ans, temp;

ll pow2[30];
ll rest[70];
vector<ll> b;

int main(void) {
	b.resize(100);
	ll num = 1;
	for (ll i = 0; i < 30; i++) {
		pow2[i] = num;
		num *= 2;
	}
	num /= 2;
	for(ll i = 0; i < 70; i++) {
		rest[i] = num + i + 1;
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N; // always 100

		for (ll i = 0; i < 30; i++) {
			cout << pow2[i] << ' ';
		}
		for (ll i = 0; i < 70; i++) {
			cout << rest[i] << ' ';
		}
		cout << endl;

		for (ll i = 0; i < 100; i++) {
			cin >> b[i];
		}
		sort(b.rbegin(), b.rend());

		ll aSum = 0, bSum = 0;
		for (ll i = 0; i < 70; i++) {
			if (aSum <= bSum) {
				aSum += rest[i];

				cout << rest[i] << ' ';
			}
			else {
				bSum += rest[i];
			}
		}
		for (ll i = 0; i < 100; i++) {
			if (aSum <= bSum) {
				aSum += b[i];

				cout << b[i] << ' ';
			}
			else {
				bSum += b[i];
			}
		}
		for (ll i = 0; i < 30; i++) {
			if (aSum <= bSum) {
				aSum += b[i];

				cout << b[i] << ' ';
			}
			else {
				bSum += b[i];
			}
		}
		cout << endl;
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
