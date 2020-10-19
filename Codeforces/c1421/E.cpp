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

ll N, M, ans, temp;
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	ll sum = 0;
	ans = -LINF;
	for (ll i = 0; i < N; i++) {
		cin >> temp;
		m.push_back({ temp, i + 1 });
		sum += temp;
	}
	if (N % 3 == 1) {
		ans = max(ans, sum);
	}

	sort(m.rbegin(), m.rend());
	ll allEven = 1;
	for (ll i = 0; i < N; i++) {
		sum -= m.back().first * 2;
		allEven = allEven && (m.back().second % 2 == 0);
		if ((N + i + 1) % 3 == 1) {
			if (allEven && N % 2 == 1 && N / 2 == i + 1) {
				ans = max(ans, sum + m.back().first * 2 - m[m.size() - 2].first * 2);
			}
			else {
				ans = max(ans, sum);
			}
		}
		m.pop_back();
	}

	cout << ans;

	return 0;
}
