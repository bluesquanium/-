#include <iostream>
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

ll N, A, R, M, ans = LINF;
vector<ll> m;

ll findCost(ll h) {
	ll cost, a = 0, r = 0;
	for (ll i = 0; i < N; i++) {
		if (m[i] < h) {
			a += h - m[i];
		}
		else {
			r += m[i] - h;
		}
	}
	
	if (a > r) {
		cost = A * (a - r) + M * r;
	}
	else {
		cost = R * (r - a) + M * a;
	}
	return cost;
}

void BinarySearch(ll s, ll e) {
	while (s < e) {
		ll mid = (s + e) / 2;
		ll cur_cost = findCost(mid), next_cost = findCost(mid + 1);
		if (cur_cost < next_cost) {
			ans = min(ans, cur_cost);
			e = mid;
		}
		else {
			ans = min(ans, next_cost);
			s = mid + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> A >> R >> M;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	M = min(M, A + R);

	BinarySearch(0, 1000000001);

	cout << ans;

	return 0;
}
