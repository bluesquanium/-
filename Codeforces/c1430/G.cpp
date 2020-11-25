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

#define MAXN 18
#define MAXM (1 << MAXN)

ll N, M, temp;
ll ans[MAXN];

ll c[MAXN];
vector<ll> e[MAXN];

bool p[MAXN + 1][MAXN + 1][MAXM];
ll dp[MAXN + 1][MAXN + 1][MAXM];
ll mask[MAXN];

vector<ll> order;
ll visited[MAXN];
void topology_dfs(ll x, bool build_topo) {
	if (visited[x] == 0) {
		visited[x] = 1;
		
		for (auto v : e[x]) {
			if (visited[v] == 0) {
				topology_dfs(v, build_topo);
			}
		}
		if (build_topo) {
			order.push_back(x);
		}
	}
}

ll build_mask(ll x) {
	ll mask = 0;
	for (ll i = 0; i < N; i++) {
		mask |= (visited[i] << i);
	}
	mask ^= (1 << x);
	return mask;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		e[u].push_back(v);
		c[u] += w;
		c[v] -= w;
	}

	for (ll i = 0; i < N; i++) {
		topology_dfs(i, true);
	}

	reverse(order.begin(), order.end());
	for (ll i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));
		topology_dfs(i, false);
		mask[i] = build_mask(i);
	}

	for (ll i = 0; i <= N; i++) {
		for (ll j = 0; j <= N; j++) {
			for (ll k = 0; k < MAXM; k++) {
				dp[i][j][k] = LINF;
			}
		}
	}
	dp[0][0][0] = 0;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j <= N; j++) {
			for (ll k = 0; k < MAXM; k++) {
				if (dp[i][j][k] == LINF) {
					continue;
				}
				if (j == N) {
					if (dp[i + 1][0][k] > dp[i][j][k]) {
						dp[i + 1][0][k] = dp[i][j][k];
					}
				}
				else {
					ll v = order[j];
					ll add = i * c[v];
					ll nk = k | (1 << v);
					if (dp[i][j + 1][k] > dp[i][j][k]) {
						dp[i][j + 1][k] = dp[i][j][k];
						p[i][j + 1][k] = false;
					}
					if ((nk != k) && ((k & mask[v]) == mask[v])) {
						if (dp[i][j + 1][nk] > dp[i][j][k] + add) {
							dp[i][j + 1][nk] = dp[i][j][k] + add;
							p[i][j + 1][nk] = true;
						}
					}
				}
			}
		}
	}

	ll i = N;
	ll j = 0;
	ll k = (1 << N) - 1;
	while (i > 0 || j > 0 || k > 0) {
		if (j == 0) {
			j = N;
			i--;
		}
		else {
			if (p[i][j][k]) {
				ll v = order[j - 1];
				ans[v] = i;
				k ^= (1 << v);
			}
			j--;
		}
	}


	for (ll i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}
