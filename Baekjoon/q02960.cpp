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

ll N, K, ans;
ll m[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;

	ll cnt = 0;
	for (ll i = 2; i <= N; i++) {
		if (m[i] == 0) {
			m[i] = 1;
			cnt++;
			if (cnt == K) {
				cout << i;
				return 0;
			}

			ll j = i * 2;
			while (j <= N) {
				if (m[j] == 0) {
					m[j] = 1;
					cnt++;
					if (cnt == K) {
						cout << j;
						return 0;
					}
				}
				j += i;
			}
		}
	}

	cout << ans;

	return 0;
}
