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

ll N, K, ans, temp;
vector<ll> m;

ll calTime(ll val, ll splitNum) {
	return (val % splitNum) * (val / splitNum + 1) * (val / splitNum + 1)
		+ (splitNum - val % splitNum) * (val / splitNum) * (val / splitNum);
}

ll calPotential(pll a) {
	ll val = a.first, splitNum = a.second;
	ll before = calTime(val, splitNum);
	splitNum++;
	ll after = calTime(val, splitNum);
	return before - after;
}

struct cmp {
	bool operator()(pll a, pll b) {
		return calPotential(a) < calPotential(b);
	}
};
priority_queue<pll, vector<pll>, cmp > pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		pq.push({ m[i], 1 });
	}

	for (ll i = K - N; i > 0; i--) {
		pll target = pq.top(); pq.pop();
		target.second++;
		pq.push(target);
	}

	while (!pq.empty()) {
		pll cur = pq.top(); pq.pop();
		ans += calTime(cur.first, cur.second);
	}

	cout << ans;

	return 0;
}
