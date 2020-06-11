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

ll T, N, X, ans;
ll od, ev;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		od = ev = 0;
		cin >> N >> X;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] % 2 == 0) {
				ev++;
			}
			else {
				od++;
			}
		}

		for (ll i = 1; i <= od && i <= X; i += 2) {
			if (i + ev >= X) {
				ans = 1;
				break;
			}
		}

		if (ans) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
