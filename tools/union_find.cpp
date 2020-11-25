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
	// Root인 경우 x를 반환
	if (x == parent[x]) {
		return x;
	}
	
	// 아니면 Root를 찾아감
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
