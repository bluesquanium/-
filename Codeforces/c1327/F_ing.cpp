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

ll N, K, M, ans, cur;
ll check1[MAX + 1];
vector< vector<ll> > check0;
ll dp[MAX + 1];

typedef struct {
	int l, r, x;
} Condition;
vector<Condition> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K >> M;
	m.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> m[i].l >> m[i].r >> m[i].x;
		m[i].l--; m[i].r--;
	}
	ans = 1;
	for (int k = 0; k < K; k++) {
		memset(dp, 0, sizeof(ll) * (MAX + 1));
		memset(check1, 0, sizeof(ll) * (MAX + 1));
		check0.clear();
		check0.resize(N);

		for (int i = 0; i < M; i++) {
			if ((m[i].x >> k) & 1) {
				check1[m[i].l]++;
				check1[m[i].r + 1]--;
			}
			else {
				check0[m[i].r].push_back(m[i].l);
			}
		}
		cur = 1;
		for (int i = 0; i < N; i++) {
			if (i != 0) {
				check1[i] += check1[i - 1];
			}

			if (check0[i].size() != 0) {
				ll maxL = -1;
				for (int j = 0; j < check0[i].size(); j++) {
					maxL = max(maxL, check0[i][j]);
				}
				for (int j = 0; j < maxL; j++) {
					dp[j] = 0;
				}
				if (check1[i] != 0) {
					cur = 0;
				}
				for (int j = maxL; j < i; j++) {
					cur += dp[j];
				}
			}

			if (check1[i] == 0) {
				dp[i] = cur;
				cur *= 2;
			}
			
		}
		ans *= cur;
	}

	cout << ans;

	return 0;
}
