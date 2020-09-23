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

ll N, M, ans, temp;
vector<ll> m, result;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	ll curSmall = 0, curBig = N / 2;

	ans = 0;
	result.push_back(m[curBig]);
	ll prevBig = m[curBig++];
	ll small;
	for (ll i = 1; i < N; i++) {
		if (i % 2 == 1) { // small
			small = m[curSmall];
			result.push_back(m[curSmall++]);
		}
		else { // big
			result.push_back(m[curBig]);
			if (small < prevBig && small < m[curBig]) {
				ans++;
			}
			prevBig = m[curBig++];
		}
	}

	cout << ans << '\n';
	for (ll i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}
