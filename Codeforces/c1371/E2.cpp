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

ll maxi = 1;
ll N, P;
vector<ll> m;
vector<ll> ans;
vector<ll> points;

ll success(ll mid) {
	ll cur = points.size() - 1;
	while (m[points[cur]] > mid) {
		cur--;
		if (cur < 0) {
			return -1;
		}
	}

	if (mid >= maxi) {
		if (P > N) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		ll check = 1;
		for (ll i = 0; i < N; i++) {
			if (cur + 1 < points.size() && mid + i >= m[points[cur + 1]]) {
				cur++;
			}
			// points[cur] + 1 == °¹¼ö
			if ((points[cur] + 1 - i) == 0) {
				return -1;
			}
			else if ((points[cur] + 1 - i) % P == 0) {
				check = 0;
				break;
			}
		}
		if (check) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void solve() {
	ll start = 1, end = 1000000001;
	ll ceil = -1;
	while (start < end) {
		ll mid = (end + start) / 2;
		if (success(mid)) {
			ceil = max(ceil, mid);
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	if (ceil == -1) {
		return;
	}

	start = 1; end = 1000000001;
	ll bot = 0;
	while (start < end) {
		ll mid = (end + start) / 2;
		if (success(mid) == -1) {
			bot = max(bot, mid);
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	for (ll i = bot + 1; i <= ceil; i++) {
		ans.push_back(i);
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> P;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		maxi = max(maxi, m[i]);
	}
	sort(m.begin(), m.end());

	ll prev = m[0];
	for (ll i = 1; i < N; i++) {
		if (m[i] != prev) {
			points.push_back(i - 1);
			prev = m[i];
		}
	}
	points.push_back(N - 1);

	//binary search
	solve();

	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	} cout << '\n';

	return 0;
}
