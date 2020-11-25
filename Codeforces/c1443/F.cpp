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

#define MOD 998244353

ll T, N, K, ans, temp;
vector<ll> a, b;
ll target[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		map<ll, ll> pos;
		cin >> N >> K;
		a.clear(); a.resize(N);
		b.clear(); b.resize(K);
		for (ll i = 0; i < N; i++) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		for (ll i = 0; i < K; i++) {
			cin >> b[i];
			target[b[i]] = 1;
		}

		ans = 1;
		for (ll i = 0; i < K; i++) {
			ll idx = pos[b[i]];
			ll mul = 2;
			if (idx - 1 >= 0) {
				if (target[a[idx - 1]] == 1) {
					mul--;
				}
			}
			else {
				mul--;
			}
			if (idx + 1 < N) {
				if (target[a[idx + 1]] == 1) {
					mul--;
				}
			}
			else {
				mul--;
			}

			ans *= mul;
			ans %= MOD;
			target[b[i]] = 0;
		}
		

		cout << ans << '\n';
	}

	return 0;
}
