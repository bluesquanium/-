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

ll N, M, ans;
ll m[16][16];
ll visited[16];

void solve(ll cur, ll cnt, ll sum) {
	if (cnt == N - 1) {
		ans = min(ans, sum + m[cur][0]);
		return;
	}

	for (ll i = 1; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			solve(i, cnt + 1, sum + m[cur][i]);
			visited[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ans = LINF;

	cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}

	solve(0, 0, 0);

	cout << ans;

	return 0;
}
