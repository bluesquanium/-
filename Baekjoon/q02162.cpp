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
typedef struct {
	ll x1, x2, y1, y2;
} Line;
vector<Line> m;

#define UMAX 3000
ll parent[UMAX + 1];
void Init() {
	for (ll i = 0; i <= UMAX; i++) {
		parent[i] = i;
	}
}
ll Find(ll x) {
	if (x == parent[x]) {
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
	parent[y] = x;
}

ll groups[UMAX + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Init();

	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i].x1 >> m[i].y1 >> m[i].x2 >> m[i].y2;
	}

	for (ll i = 0; i < N; i++) {
		groups[Find(i)]++;
	}
	ll gCnt = 0, maxi = 0;
	for (ll i = 0; i < N; i++) {
		if (groups[i] != 0) {
			gCnt++;
			maxi = max(maxi, groups[i]);
		}
	}

	cout << gCnt << '\n';
	cout << maxi;

	return 0;
}
