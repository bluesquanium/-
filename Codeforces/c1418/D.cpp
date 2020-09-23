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

ll N, Q, ans, t, x;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	for (ll i = 0; i < Q; i++) {
		cin >> t >> x;
	}

	cout << ans;

	return 0;
}
