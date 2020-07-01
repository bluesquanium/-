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

#define NUMNODE 1000
vector<pll> edge_to[NUMNODE + 1];
bool visited[1000 + 1];
ll N, M, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (ll i = 0; i < M; i++) {
		ll u, v, cost;
		cin >> u >> v >> cost;
		edge_to[u].push_back({ v, cost });
		edge_to[v].push_back({ u, cost });
	}

	visited[1] = true;
	for(ll n = 0; n < N - 1; n++) {
		pll * mini = NULL;
		for (ll i = 1; i <= N; i++) {
			if (visited[i]) {
				for (ll j = 0; j < edge_to[i].size(); j++) {
					if (visited[edge_to[i][j].first] == false) {
						if (mini == NULL || mini->second > edge_to[i][j].second) {
							mini = &edge_to[i][j];
						}
					}
				}
			}
		}

		visited[mini->first] = true;
		ans += mini->second;
	}

	cout << ans;

	return 0;
}
