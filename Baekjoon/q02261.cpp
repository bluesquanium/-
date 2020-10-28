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

ll N, ans, temp;
vector<pll> m;

ll dist(pll a, pll b) {
	ll x = abs(a.first - b.first), y = abs(a.second - b.second);
	return x * x + y * y;
}

struct cmp {
	bool operator()(pll a, pll b) const {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		else {
			return a.second < b.second;
		}
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}
	sort(m.begin(), m.end());
	ans = dist(m[0], m[1]);
	set<pll, cmp> candidates;
	candidates.insert(m[0]);
	candidates.insert(m[1]);

	ll start = 0;
	for (ll i = 2; i < N; i++) {
		while (start < i) {
			ll diff_x = abs(m[i].first - m[start].first);
			if (diff_x * diff_x > ans) {
				candidates.erase(m[start++]);
			}
			else {
				break;
			}
		}

		ll d = sqrt(ans) + 1;
		auto lower = candidates.lower_bound({ -10000, m[i].second - d });
		auto upper = candidates.upper_bound({ 10000, m[i].second + d });
		for (auto iter = lower; iter != upper; iter++) {
			ans = min(ans, dist(m[i], *iter));
		}

		candidates.insert(m[i]);
	}


	cout << ans;

	return 0;
}
