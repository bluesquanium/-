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

ll T, N, M, ans, temp;
vector<ll> m1, m2, num1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	cin >> N;
	m1.clear(); m1.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m1[i];
	}
	for (ll i = 0; i < N; i++) {
		ll sum = 0;
		for (ll j = i; j < N; j++) {
			sum += m1[j];
			num1.push_back(sum);
		}
	}
	sort(num1.begin(), num1.end());

	cin >> M;
	m2.clear(); m2.resize(M);
	for (ll i = 0; i < M; i++) {
		cin >> m2[i];
	}
	for (ll i = 0; i < M; i++) {
		ll sum = 0;
		for (ll j = i; j < M; j++) {
			sum += m2[j];
			auto lower = lower_bound(num1.begin(), num1.end(), T - sum);
			auto upper = upper_bound(num1.begin(), num1.end(), T - sum);
			ans += upper - lower;
		}
	}

	cout << ans << '\n';

	return 0;
}
