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

ll N, M, ans, t;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 1; i <= N; i++) {
		cin >> t;
		ll prev = m[0];
		m[0] += t;
		for (int j = 1; j < i; j++) {
			cin >> t;

			ll temp = m[j];
			m[j] = t + (m[j] > prev ? m[j] : prev);
			prev = temp;
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, m[i]);
	}

	cout << ans;

	return 0;
}
