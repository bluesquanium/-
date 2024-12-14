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

#define UMAX 10000
ll parent[UMAX + 1];
void Init() {
	for (int i = 0; i <= UMAX; i++) {
		parent[i] = i;
	}
}
ll Find(ll x) {
	if (x != parent[x]) {
		parent[x] = Find(parent[x]);
	}
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
