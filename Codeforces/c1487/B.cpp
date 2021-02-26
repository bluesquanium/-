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

ll T, N, M, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		if (N % 2 == 0) { // even
			ans = (K - 1) % N + 1;
		}
		else { // odd
			if (K / (N / 2) == 0) {
				ans = K;
			}
			else {
				K = (K - 1) % (N * (N / 2));
				ans = ((K + max(0LL, K / (N / 2))) % N) + 1;
			}
		}
		
		cout << ans << '\n';
	}

	return 0;
}
