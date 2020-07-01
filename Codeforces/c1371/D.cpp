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

ll T, N, K, ans;
ll m[300][300];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < N; j++) {
				m[i][j] = 0;
			}
		}

		ll i = 0, j = 0, cnt = 0;
		while (cnt < K) {
			m[i][j] = 1;
			j = (j + 1) % N;
			i++;
			if (i == N) {
				i = 0;
				j = (j + 1) % N;
			}

			cnt++;
		}

		ll mini = (K / N);
		ll maxi = mini;
		if (K % N != 0) {
			maxi++;
		}
		
		cout << (maxi - mini) * (maxi - mini) * 2 << '\n';
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < N; j++) {
				cout << m[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}
