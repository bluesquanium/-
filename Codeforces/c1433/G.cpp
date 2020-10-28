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

ll N, M, K, ans, temp;
vector<pll> e[1001];
vector<pll> edges;
vector<pll> q;

ll mem[1001][1001];

void sp(ll root) {
	ll visited[1001];
	for (ll i = 1; i <= N; i++) {
		visited[i] = INF;
	}
	visited[root] = 0;

	priority_queue< pll, vector<pll>, greater<pll> > pq;
	for (ll i = 0; i < e[root].size(); i++) {
		pq.push({ e[root][i].second, e[root][i].first });
	}

	while (!pq.empty()) {
		pll cur = pq.top(); pq.pop();
		if (visited[cur.second] > cur.first) {
			visited[cur.second] = cur.first;
		}

		for (ll i = 0; i < e[cur.second].size(); i++) {
			if (visited[cur.second] + e[cur.second][i].second < visited[e[cur.second][i].first]) {
				pq.push({ visited[cur.second] + e[cur.second][i].second, e[cur.second][i].first });
			}
		}
	}

	for (ll i = 1; i <= N; i++) {
		mem[root][i] = visited[i];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;

	for (ll i = 0; i < M; i++) {
		ll x, y, w;
		cin >> x >> y >> w;
		e[x].push_back({ y, w });
		e[y].push_back({ x, w });
		edges.push_back({ x, y });
	}

	for (ll i = 1; i <= N; i++) {
		sp(i);
	}

	for (ll i = 0; i < K; i++) {
		ll a, b;
		cin >> a >> b;
		q.push_back({ a, b });
	}

	ans = LINF;
	for (ll i = 0; i < M; i++) {
		ll sum = 0;
		for (ll j = 0; j < K; j++) {
			ll start = q[j].first, end = q[j].second;

			sum += min(mem[start][end], min(mem[start][edges[i].first] + mem[edges[i].second][end], mem[start][edges[i].second] + mem[edges[i].first][end]));
		}
		ans = min(ans, sum);
	}

	cout << ans;

	return 0;
}
