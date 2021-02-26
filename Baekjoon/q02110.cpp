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

ll N, C, ans, temp;
vector<ll> m;

bool isPossible(ll gap) {
	auto prev = m.begin();
	for (ll i = 1; i < C; i++) {
		auto next = lower_bound(prev, m.end(), *prev + gap);
		if (next == m.end()) {
			return false;
		}
		prev = next;
	}

	return true;
}

void solve() {
	ll s = 1, e = 1000000001;
	while (s + 1 < e) {
		ll mid = (s + e) / 2;
		if (isPossible(mid)) {
			s = mid;
		}
		else {
			e = mid;
		}
	}

	ans = s;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> C;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	solve();

	cout << ans;

	return 0;
}
