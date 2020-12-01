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

#define XMAX 1000000

ll T, X, ans, temp;
ll mem[XMAX + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	mem[1] = 1;
	ll prev = 0;
	ll isStop = false;
	for (ll k = 1; k < XMAX; k++) {
		ll to = prev + k;
		for (ll i = prev + 1; i <= to; i++) {
			mem[i] = k;
			if (i == XMAX) {
				isStop = true;
				break;
			}
		}
		mem[to - 1] = k + 1;
		if (isStop) {
			break;
		}
		prev = to;
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> X;

		cout << mem[X] << '\n';
	}

	return 0;
}
