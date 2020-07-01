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

ll T, N, ans;
vector<ll> a, b;

ll check(ll mid) {
	ll ret = 0;
	if (a[0] - mid < 0) {
		ret = -1;
	}
	ll next = b[0] - mid;
	for (ll i = 1; i < N; i++) {
		if (next + b[i] >= a[i]) {
			if (ret == 0 && a[i] - next < 0) {
				ret = 1;
			}
			next = a[i] - next > 0 ? a[i] - next : 0;
			next = b[i] - next;
		}
		else {
			if (ret != 0) {
				return ret;
			}
			else {
				return -1;
			}
		}
	}

	if (mid + next < a[0]) {
		if (ret == 1) {
			return 1;
		}
		else {
			return 1;
		}
	}

	return 0;
}

void solve() {
	ll start = 0, end = b[0] + 1;
	while (start < end) {
		ll mid = (end + start) / 2;
		if (check(mid) == 0) {
			ans = 1;
			break;
		}
		else if (check(mid) == -1) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		a.clear(); a.resize(N);
		b.clear(); b.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < N; i++) {
			cin >> b[i];
		}

		solve();

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
