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

ll num[6];

void solve(ll cur, ll cnt) {
	if (cnt == 6) {
		for (ll i = 0; i < 6; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (ll i = cur; i < N; i++) {
		num[cnt] = m[i];
		solve(i + 1, cnt + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	while (cin >> N && N != 0) {
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		solve(0, 0);
		cout << '\n';
	}

	return 0;
}
