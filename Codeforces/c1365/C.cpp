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

ll N, ans;
vector<ll> a, b;
ll pos[200001];
ll cost[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	a.resize(N); b.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (ll i = 0; i < N; i++) {
		cin >> b[i];
		ll move = i - pos[b[i]];
		if (move < 0) {
			move += N;
		}
		cost[move]++;
	}

	for (ll i = 0; i <= 200000; i++) {
		ans = max(ans, cost[i]);
	}

	cout << ans;

	return 0;
}
