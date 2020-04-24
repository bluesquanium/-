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

#define MAXN 200001

ll N, K, u, v, ans;
ll num_child[MAXN];
ll depths[MAXN];
ll dets[MAXN];
vector<ll> conj[MAXN];
vector<ll> m;

ll Dfs(ll cur, ll prev) {
	depths[cur] = depths[prev] + 1;
	for (int i = 0; i < conj[cur].size(); i++) {
		if (prev != conj[cur][i]) {
			num_child[cur] += Dfs(conj[cur][i], cur) + 1;
		}
	}

	dets[cur] = num_child[cur] - depths[cur];

	return num_child[cur];
}

bool cmp(ll a, ll b) {
	return a > b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (ll i = 1; i < N; i++) {
		cin >> u >> v;
		conj[u].push_back(v);
		conj[v].push_back(u);
	}
	depths[0] = -1;
	Dfs(1, 0);

	nth_element(dets + 1, dets + N - K, dets + N + 1, cmp);
	for (ll i = 1; i <= N - K; i++) {
		ans += dets[i];
	}

	cout << ans;


	return 0;
}
