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

ll T, N, p, prev_p, c, prev_c, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 1;
		prev_p = prev_c = 0;
		cin >> N;
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> p >> c;
			if (p < prev_p || c < prev_c || p < c || p - prev_p < c - prev_c) {
				ans = 0;
			}
			prev_p = p;
			prev_c = c;
		}

		if (ans) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
