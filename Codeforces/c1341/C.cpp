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

string ans;
ll T, N, M;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = "Yes";
		cin >> N;
		m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ll cur = m[0];
		for (ll i = 1; i < N; i++) {
			if (m[i] - 1 != cur) {
				if (m[i] > cur + 1) {
					ans = "No";
					break;
				}
			}
			cur = m[i];
		}

		cout << ans << '\n';
	}

	return 0;
}
