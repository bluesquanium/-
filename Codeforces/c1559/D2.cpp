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

#define UMAX 100000
ll parent1[UMAX + 1], parent2[UMAX + 1];
void Init(ll mtype) {
	if (mtype == 1) {
		for (int i = 0; i <= UMAX; i++) {
			parent1[i] = i;
		}
	}
	else {
		for (int i = 0; i <= UMAX; i++) {
			parent2[i] = i;
		}
	}
}
ll Find(ll x, ll mtype) {
	if (mtype == 1) {
		// Root인 경우 x를 반환
		if (x == parent1[x]) {
			return x;
		}

		// 아니면 Root를 찾아감
		parent1[x] = Find(parent1[x], mtype);
		return parent1[x];
	}
	else {
		// Root인 경우 x를 반환
		if (x == parent2[x]) {
			return x;
		}

		// 아니면 Root를 찾아감
		parent2[x] = Find(parent2[x], mtype);
		return parent2[x];
	}
}
void Union(ll x, ll y, ll mtype) {
	if (mtype == 1) {
		x = Find(x, mtype);
		y = Find(y, mtype);

		if (x > y) {
			swap(x, y);
		}
		parent1[y] = x;
	}
	else {
		x = Find(x, mtype);
		y = Find(y, mtype);

		if (x > y) {
			swap(x, y);
		}
		parent2[y] = x;
	}
}

ll N, M1, M2, ans, temp;
vector<pll> m1, m2;
vector<ll> group1[UMAX + 1], group2[UMAX + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M1 >> M2;
	m1.resize(M1);
	m2.resize(M2);
	for (ll i = 0; i < M1; i++) {
		cin >> m1[i].first >> m1[i].second;
	}
	for (ll i = 0; i < M2; i++) {
		cin >> m2[i].first >> m2[i].second;
	}

	if (M1 < M2) {
		vector<pll> temp;
		temp = m1;
		m1 = m2;
		m2 = temp;

		ll tempLL = M1;
		M1 = M2;
		M2 = tempLL;
	}

	Init(1);
	Init(2);
	for (ll i = 0; i < M1; i++) {
		Union(m1[i].first, m1[i].second, 1);
	}
	for (ll i = 0; i < M2; i++) {
		Union(m2[i].first, m2[i].second, 2);
	}
	for (ll i = 1; i <= N; i++) {
		group1[Find(i, 1)].push_back(i);
		group2[Find(i, 2)].push_back(i);
	}

	ans = N - 1 - M1;
	cout << ans << '\n';

	for (ll i = 1; i <= N; i++) {
		if (Find(1, 1) != Find(i, 1)) {
			for (ll j = 0; j < group1[1].size(); j++) {
				ll from = group1[1][j];
				if (Find(from, 2) != Find(i, 2)) {
					for (ll k = 0; k < group1[Find(i, 1)].size(); k++) {
						group1[1].push_back(group1[Find(i, 1)][k]);
					}
					group1[Find(i, 1)].clear();
					for (ll k = 0; k < group2[Find(i, 2)].size(); k++) {
						group2[Find(from, 2)].push_back(group2[Find(i, 2)][k]);
					}
					group2[Find(i, 2)].clear();
					Union(from, i, 1);
					Union(from, i, 2);
					cout << from << ' ' << i << '\n';
					break;
				}
			}
		}
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
