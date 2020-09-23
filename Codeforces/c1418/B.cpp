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

ll T, N, M, ans, temp;
vector<ll> m, isLocked, factors;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		isLocked.clear(); isLocked.resize(N);
		factors.clear();
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		for (ll i = 0; i < N; i++) {
			cin >> isLocked[i];
			if (isLocked[i] == 0) {
				factors.push_back(m[i]);
			}
		}
		sort(factors.rbegin(), factors.rend());

		ll cur = 0;
		for (ll i = 0; i < N; i++) {
			if (isLocked[i]) {
				cout << m[i] << ' ';
			}
			else {
				cout << factors[cur++] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
