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

ll N, K, ans, temp;
typedef struct {
	ll l, r, a;
} wave;
vector<wave> m;
ll mem[2000];

void solve() {
	mem[0] = 0;
	for (ll i = 0; i < N; i++) {
		if (mem[i] == LINF) {
			continue;
		}
		ll rem = K, total = mem[i];
		for (ll j = i; j < N; j++) {
			ll reloadCnt = (max(0LL, m[j].a - rem) + K - 1) / K;
			if (reloadCnt > m[j].r - m[j].l) {
				break;
			}

			total += m[j].a;
			rem = (rem + reloadCnt * K) - m[j].a;
			if (j + 1 < N) {
				if (reloadCnt < m[j + 1].l - m[j].l) {
					mem[j + 1] = min(mem[j + 1], total + rem);
				}
			}
			else {
				ans = min(ans, total);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i].l >> m[i].r >> m[i].a;
	}

	ans = LINF;
	for (ll i = 0; i < 2000; i++) {
		mem[i] = LINF;
	}

	solve();

	if (ans == LINF) {
		ans = -1;
	}
	cout << ans;

	return 0;
}
