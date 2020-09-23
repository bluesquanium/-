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

ll T, X, ans, temp;
ll m[100000];
ll mem[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll x = 1;
	m[1] = 1;
	for (ll i = 2; i <= 31; i++) {
		x *= 2;
		m[i] = m[i - 1] * 2 + x * x;
	}
	mem[1] = 1;
	for (ll i = 2; i <= 31; i++) {
		mem[i] = m[i] + mem[i - 1];
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> X;

		for (ll i = 1; i < 32; i++) {
			if (X < mem[i]) {
				cout << i - 1 << '\n';
				break;
			}
		}
	}

	return 0;
}
