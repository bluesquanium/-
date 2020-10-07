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

ll T, N, A, B, dA, dB, ans, temp;
vector<ll> m;

#define NUMNODE 100000
typedef struct {
	ll depth;
	ll size;
	ll parent;
} Node;
Node nodes[NUMNODE + 1];
vector<ll> e[NUMNODE + 1];

void dfs(ll u) {
	nodes[u].size = 1;
	for (auto v : e[u]) {
		if (nodes[u].parent == v) {
			continue;
		}
		nodes[v].parent = u;
		nodes[v].depth = nodes[u].depth + 1;
		dfs(v);
		nodes[u].size += nodes[v].size;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		cin >> N >> A >> B >> dA >> dB;
		for (ll i = 1; i <= N; i++) {
			e[i].clear();
			nodes[i].depth = 0;
			nodes[i].parent = 0;
			nodes[i].size = 0;
		}
		for (ll i = 0; i < N - 1; i++) {
			ll u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		if (dA * 2 < dB) {
			dfs(A);
			if (nodes[B].depth - nodes[A].depth > dA) {
				ll maxi = 0, root = -1;
				for (ll i = 1; i <= N; i++) {
					if (nodes[i].depth > maxi) {
						root = i;
						maxi = nodes[i].depth;
					}
				}
				for (ll i = 1; i <= N; i++) {
					nodes[i].depth = 0;
					nodes[i].parent = 0;
					nodes[i].size = 0;
				}
				dfs(root);
				maxi = 0; root = -1;
				for (ll i = 1; i <= N; i++) {
					if (nodes[i].depth > maxi) {
						root = i;
						maxi = nodes[i].depth;
					}
				}

				if (min(maxi, dB) > dA * 2) {
					ans = 0;
				}
			}
		}

		if (ans) {
			cout << "Alice\n";
		}
		else {
			cout << "Bob\n";
		}
	}

	return 0;
}
