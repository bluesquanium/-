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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ll ans = 0;
		ll maxStep = 1;
		ll curStep = 0;
		for (ll i = 1; i < N; i++) {
			if (curStep == 0) {
				curStep = maxStep;
				ans++;
			}
			curStep--;
			ll j = i;
			while (j + 1 < N) {
				if (m[j] < m[j + 1]) {
					j++;
					maxStep++;
				}
				else {
					break;
				}
			}
			i = j;
		}

		cout << ans << '\n';
	}

	return 0;
}
