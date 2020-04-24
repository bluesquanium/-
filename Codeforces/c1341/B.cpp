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

pll ans;
ll T, N, K, cur, tail;
vector<ll> m;
ll peaks[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cur = tail = 0;
		ans = { 1, 0 };
		cin >> N >> K;
		memset(peaks, 0, sizeof(ll)*N);
		m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		for (ll i = 1; i < N - 1; i++) {
			if (m[i - 1] < m[i] && m[i] > m[i + 1]) {
				peaks[i] = 1;
			}
		}

		ll next_bonus = 0, cnt = 1;
		for (int i = 0; i < K; i++) {
			cnt += next_bonus;
			next_bonus = 0;

			if (peaks[i]) {
				next_bonus = 1;
			}
		}

		for (int i = K; i < N; i++) {
			cnt -= peaks[tail];
			if (ans.first < cnt) {
				ans = { cnt, tail };
			}

			cnt += next_bonus;
			next_bonus = 0;

			if (peaks[i]) {
				next_bonus = 1;
			}
			tail++;
		}
		cnt -= peaks[tail];
		if (ans.first < cnt) {
			ans = { cnt, tail };
		}

		cout << ans.first << ' ' << ans.second + 1 << '\n';
	}

	return 0;
}
