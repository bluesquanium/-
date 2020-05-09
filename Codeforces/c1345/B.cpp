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

#define MAX 100000

ll T, N, M, ans;
vector<ll> m;
ll mem[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 1; i < MAX; i++) {
		mem[i] = (3 * i * i + i) / 2;
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		while (1) {
			ll * cur = lower_bound(mem + 1, mem + MAX, N);
			if (N - *cur < 0) {
				cur--;
				if (*cur < 1) {
					break;
				}
			}
			N -= *(cur);
			if (N >= 0) {
				ans++;
			}
			else {
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
