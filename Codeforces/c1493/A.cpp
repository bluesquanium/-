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

ll T, N, K, ans, temp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> K;

		ans += N - K;
		ans += K / 2;
		cout << ans << '\n';
		for (ll i = (K + 1) / 2; i < K; i++) {
			cout << i << ' ';
		}
		for (ll i = K + 1; i <= N; i++) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}
