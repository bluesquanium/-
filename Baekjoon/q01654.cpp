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

#define MAX 2147483648

ll N, K, ans;
vector<ll> m;

void binarySearch() {
	ll s = 1, e = MAX + 1;
	while (s < e) {
		ll mid = (s + e) / 2;
		ll cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += m[i] / mid;
		}
		if (cnt < N) {
			e = mid;
		}
		else {
			s = mid + 1;
			ans = max(ans, mid);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> K >> N;
	m.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> m[i];
	}

	binarySearch();
	cout << ans;

	return 0;
}
