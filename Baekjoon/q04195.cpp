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

ll T, N, M, ans, temp;

#define UMAX 10000
ll parent[UMAX + 1];
ll memCnt[UMAX + 1];
void Init() {
	for (int i = 0; i <= UMAX; i++) {
		parent[i] = i;
		memCnt[i] = 1;
	}
}
ll Find(ll x) {
	// Root인 경우 x를 반환
	if (x == parent[x]) {
		return x;
	}
	else {
		// 아니면 Root를 찾아감
		ll p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}
void Union(ll x, ll y) {

	x = Find(x);
	y = Find(y);

	if (x > y) {
		swap(x, y);
	}
	if (x != y) {
		memCnt[x] += memCnt[y];
	}
	parent[y] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		Init();
		map<string, ll> m;

		cin >> N;

		ll cnt = 0;
		for (ll i = 0; i < N; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m.count(s1) == 0) {
				m[s1] = ++cnt;
			}
			if (m.count(s2) == 0) {
				m[s2] = ++cnt;
			}

			Union(m[s1], m[s2]);
			cout << memCnt[Find(m[s1])] << '\n';
		}
	}

	return 0;
}
