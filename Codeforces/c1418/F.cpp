#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define MAXN 200000
vector<ll> divisors[MAXN + 1];
ll ans[MAXN + 1][4];

ll N, M, L, R;

set<ll> candidateB;
ll cnt[MAXN + 1];
ll btoy[MAXN + 1];
void solve() {
	ll curL = M + 1, curR = M;

	for (ll x1 = 1; x1 <= N; x1++) {
		ll ncurL = (L + x1 - 1) / x1, ncurR = R / x1;

		//curL update
		while (ncurL < curL) {
			curL--;
			for (ll d : divisors[curL]) {
				if (cnt[d] == 0) {
					candidateB.insert(d);
				}
				cnt[d]++;

				//btoy[d]'s value is always minimum
				btoy[d] = curL;
			}
		}
		//curR update
		while (ncurR < curR) {
			for (ll d : divisors[curR]) {
				cnt[d]--;
				if (cnt[d] == 0) {
					candidateB.erase(d);
				}
			}
			curR--;
		}

		for (ll a : divisors[x1]) {
			set<ll>::iterator it = candidateB.upper_bound(a);
			if (it == candidateB.end()) {
				continue;
			}
			ll b = *it;
			ll y1 = btoy[b];
			if (b * x1 / a <= N) {
				ans[x1][0] = x1;
				ans[x1][1] = y1;
				ans[x1][2] = b * x1 / a;
				ans[x1][3] = a * y1 / b;
			}
		}
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	cin >> L >> R;

	for (ll i = 1; i <= MAXN; i++) {
		for (ll j = i; j <= MAXN; j += i) {
			divisors[j].push_back(i);
		}
	}

	solve();

	for (ll i = 1; i <= N; i++) {
		if (ans[i][0]) {
			cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}
