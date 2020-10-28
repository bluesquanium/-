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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m.clear(); m.resize(N);
		bool switch1 = false;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] == 1) {
				switch1 = true;
			}
			else {
				if (switch1) {
					ans++;
				}
			}
		}
		for (ll i = N - 1; i >= 0; i--) {
			if (m[i] == 1) {
				break;
			}
			ans--;
		}

		cout << ans << '\n';
	}

	return 0;
}
