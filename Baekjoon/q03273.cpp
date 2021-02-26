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

ll N, X, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	cin >> X;
	ll f = 0, e = N - 1;
	while (f < e) {
		if (m[f] + m[e] == X) {
			ans++;
			f++;
			e--;
		}
		else if (m[f] + m[e] < X) {
			f++;
		}
		else {
			e--;
		}
	}

	cout << ans;

	return 0;
}
