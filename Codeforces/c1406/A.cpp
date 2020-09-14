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

ll T, N, M, ans;
vector<ll> m;
ll mem[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		memset(mem, 0, sizeof(ll) * 101);
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			mem[m[i]]++;
		}

		ll check = 0;
		for (ll i = 0; i < 101; i++) {
			if (check == 0 && mem[i] < 2) {
				check = 1;
				ans += i;
			}
			if (mem[i] == 0) {
				if (check == 0) {
					ans += i;
				}
				ans += i;
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
