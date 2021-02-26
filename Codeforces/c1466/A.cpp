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
vector<ll> m;
ll mem[51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		for (ll i = 0; i <= 50; i++) {
			mem[i] = 0;
		}
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		for (ll i = 0; i < N; i++) {
			for (ll j = i + 1; j < N; j++) {
				mem[m[j] - m[i]] = 1;
			}
		}

		ans = 0;
		for (ll i = 1; i <= 50; i++) {
			ans += mem[i];
		}

		cout << ans << '\n';
	}

	return 0;
}
