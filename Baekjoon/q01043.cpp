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

ll N, M, ans, temp;
vector< vector<ll> > queries;

map<ll, ll> truths;

#define UMAX 50
ll parent[UMAX + 1];
void Init() {
	for (ll i = 0; i <= UMAX; i++) {
		parent[i] = i;
	}
}
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

	if (x > y) {
		swap(x, y);
	}
	if (truths.count(Find(y)) != 0){
		swap(x, y);
	}
	parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();

	cin >> N >> M;
	ll a;
	cin >> a;
	for (ll i = 0; i < a; i++) {
		cin >> temp;
		truths[temp] = 1;
	}
	queries.resize(M);
	for (ll i = 0; i < M; i++) {
		cin >> a;
		for (ll j = 0; j < a; j++) {
			cin >> temp;
			queries[i].push_back(temp);

			if (j != 0) {
				Union(temp, queries[i][0]);
			}
		}
	}

	for (ll i = 1; i <= N; i++) {
		Find(i);
	}
	ans = M;
	for (ll i = 0; i < queries.size(); i++) {
		for (ll j = 0; j < queries[i].size(); j++) {
			if (truths.count(Find(queries[i][j]))) {
				ans--;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
