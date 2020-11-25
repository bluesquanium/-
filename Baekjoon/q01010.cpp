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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		ans = 1;
		if (N != M) {
			if (N > M - N) {
				N = M - N;
			}
			for (ll i = 0; i < N; i++) {
				ans *= M - i;
			}
			for (ll i = 1; i <= N; i++) {
				ans /= i;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
