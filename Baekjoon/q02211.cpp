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

ll N, M, temp;
vector<pll> ans;
vector<pll> edges[1001];
ll visited[1001];

typedef struct {
	ll u, v, cost;
} Bridge;

struct cmd {
	bool operator() (Bridge a, Bridge b) {
		return a.cost > b.cost;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		edges[u].push_back({ v, c });
		edges[v].push_back({ u, c });
	}

	priority_queue< Bridge, vector<Bridge>, cmd > pq;
	visited[1] = 1;
	for (ll i = 0; i < edges[1].size(); i++) {
		Bridge t;
		t.u = 1; t.v = edges[1][i].first; t.cost = edges[1][i].second;
		pq.push(t);
	}

	while (!pq.empty()) {
		Bridge cur = pq.top(); pq.pop();
		
		if (visited[cur.v] == 0) {
			visited[cur.v] = 1;
			ans.push_back({ cur.u, cur.v });

			for (ll i = 0; i < edges[cur.v].size(); i++) {
				Bridge t;
				t.u = cur.v; t.v = edges[cur.v][i].first; t.cost = cur.cost + edges[cur.v][i].second;
				pq.push(t);
			}
		}
	}

	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}

	return 0;
}
