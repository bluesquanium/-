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

ll N, M, ans;
vector<ll> m;

#define NUMNODE 32000
typedef struct {
	ll used;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> edge_to[NUMNODE + 1];
vector<ll> edge_from[NUMNODE + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		ll u, v;
		cin >> u >> v;
		edge_to[u].push_back(v);
		edge_from[v].push_back(u);
	}

	for (ll i = 1; i <= N; i++) {
		nodes[i].used = 0;
	}

	queue<ll> st;
	for (ll i = 1; i <= N; i++) {
		if (edge_from[i].size() == 0) {
			st.push(i);
		}
	}
	while (!st.empty()) {
		ll cur = st.front(); st.pop();
		if (nodes[cur].used == false) {
			bool check = true;
			for (ll j = 0; j < edge_from[cur].size(); j++) {
				if (nodes[edge_from[cur][j]].used == false) {
					check = false;
					break;
				}
			}

			if (check) {
				cout << cur << ' ';
				nodes[cur].used = true;
				for (ll i = 0; i < edge_to[cur].size(); i++) {
					st.push(edge_to[cur][i]);
				}
			}
			else {
				st.push(cur);
			}
		}
	}

	return 0;
}
