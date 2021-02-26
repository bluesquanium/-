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

ll T, V, E, ans, temp;
vector<ll> e[20001];

set<ll> group;
ll visited[20001];
void updateGroup(ll root) {
	visited[root] = 1;
	group.insert(root);
	for (ll i = 0; i < e[root].size(); i++) {
		ll next = e[root][i];
		if (visited[next] == 0) {
			updateGroup(next);
		}
	}
}

ll toggleValue[20001];
bool checkBipartite(ll root) {
	vector<ll> st;
	st.push_back(root);
	bool toggle = 1;
	while (!st.empty()) {
		vector<ll> st2;
		while (!st.empty()) {
			ll cur = st.back(); st.pop_back();
			if (visited[cur] == 0) {
				visited[cur] = 1;
				toggleValue[cur] = toggle;
				for (ll i = 0; i < e[cur].size(); i++) {
					ll next = e[cur][i];
					if (visited[next] == 1) {
						if (toggleValue[cur] == toggleValue[next]) {
							return false;
						}
					}
					else {
						st2.push_back(next);
					}
				}
			}
		}

		st = st2;
		toggle = !toggle;
	}

	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> V >> E;
		for (ll i = 1; i <= V; i++) {
			visited[i] = 0;
			e[i].clear();
		}

		for (ll i = 0; i < E; i++) {
			ll u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		ans = 1;
		for (ll i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				group.clear();
				updateGroup(i);
				for (auto iter = group.begin(); iter != group.end(); iter++) {
					toggleValue[*iter] = -1;
					visited[*iter] = 0;
				}
				if (checkBipartite(i) == false) {
					ans = 0;
					break;
				}
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
