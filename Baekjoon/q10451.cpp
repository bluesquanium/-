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

ll T, N, ans, temp;
ll parent[1000];

ll Find(ll x) {
	if (parent[x] == x) {
		return x;
	}

	parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(ll x, ll y) {
	x = Find(x);
	y = Find(y);

	if (y < x) {
		swap(x, y);
	}
	parent[y] = Find(x);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		for (ll i = 0; i < N; i++) {
			parent[i] = i;
		}
		for (ll i = 0; i < N; i++) {
			cin >> temp;
			temp--;

			if (i != temp) {
				Union(i, temp);
			}
		}

		set<ll> check;
		for (ll i = 0; i < N; i++) {
			check.insert(Find(i));
		}

		cout << check.size() << '\n';
	}

	return 0;
}
