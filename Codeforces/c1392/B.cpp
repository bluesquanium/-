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

ll T, N, K, ans, temp;
vector<ll> m;

ll findMax() {
	ll maxi = -LINF;
	for (ll i = 0; i < N; i++) {
		if (m[i] > maxi) {
			maxi = m[i];
		}
	}
	return maxi;
}

void update() {
	ll maxi = findMax();
	for (ll i = 0; i < N; i++) {
		m[i] = maxi - m[i];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		m.clear(); m.resize(N);
		ll hasNeg = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] < 0) {
				hasNeg = 1;
			}
		}

		if (hasNeg) {
			update();
			if (K % 2 == 0) {
				update();
			}
		}
		else {
			update();
			if (K % 2 == 0) {
				update();
			}
		}

		for (ll i = 0; i < N; i++) {
			cout << m[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
