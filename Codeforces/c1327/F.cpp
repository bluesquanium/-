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
using namespace std;

#define MAX 500000
#define MOD 998244353

ll N, K, M, ans, cur, sum, curl;
ll check1[MAX + 1], check0[MAX + 1], dp[MAX + 1];

typedef struct {
	ll l, r, x;
} Condition;
vector<Condition> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K >> M;
	m.resize(M);
	for (ll i = 0; i < M; i++) {
		cin >> m[i].l >> m[i].r >> m[i].x;
		m[i].l--; m[i].r--;
	}
	ans = 1;
	for (ll k = 0; k < K; k++) {
		cur = 1;
		curl = sum = 0;
		memset(dp, 0, sizeof(ll) * (MAX + 1));
		memset(check1, 0, sizeof(ll) * (MAX + 1));
		memset(check0, -1, sizeof(ll) * (MAX + 1));

		for (ll i = 0; i < M; i++) {
			if (m[i].x & (1 << k)) {
				check1[m[i].l]++;
				check1[m[i].r + 1]--;
			}
			else {
				check0[m[i].r] = max(m[i].l, check0[m[i].r]);
			}
		}
		for (ll i = 0; i < N; i++) {
			if (i != 0) {
				check1[i] += check1[i - 1];
			}

			if (check0[i] != -1) {
				while (curl < check0[i]) {
					sum = (sum - dp[curl] + MOD) % MOD;
					dp[curl] = 0;

					curl++;
				}
				if (check1[i] != 0) {
					cur = 0;
				}
				else {
					dp[i] = cur;
				}
				cur = (cur + sum) % MOD;
				sum = (sum + dp[i]) % MOD;
			}
			else if (check1[i] == 0) {
				dp[i] = cur;
				cur = (cur * 2) % MOD;
				sum = (sum + dp[i]) % MOD;
			}
		}
		ans = (ans * cur) % MOD;
	}

	cout << ans;

	return 0;
}
