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

ll T, N, M, K, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> M >> K;

		ll maxi = min(N / K, M);
		ll mini = M - maxi;
		mini = mini < 0 ? 0 : mini;
		mini = (mini + K - 2) / (K - 1);

		cout << maxi - mini << '\n';
	}

	return 0;
}
