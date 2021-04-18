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

ll N, K, temp;
string ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;

	ll cnt = 0;
	while (1) {
		for (ll i = 0; i < K; i++) {
			ans += 'a' + i;
			cnt++;
			if (cnt == N) {
				cout << ans;
				return 0;
			}
			for (ll j = i + 1; j < K; j++) {
				ans += 'a' + i;
				cnt++;
				if (cnt == N) {
					cout << ans;
					return 0;
				}
				ans += 'a' + j;
				cnt++;
				if (cnt == N) {
					cout << ans;
					return 0;
				}
			}
		}
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
