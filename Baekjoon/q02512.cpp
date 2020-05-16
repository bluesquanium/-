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

ll N, M;
pll ans;
vector<ll> m;
ll mem[10001];

ll BinarySearchByIndex(ll s, ll e, ll target) {
	while (s < e) {
		ll mid = (s + e) / 2;
		if (target == m[mid]) {
			return mem[mid] + target * (N - mid - 1);
		}
		else if (target > m[mid]) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	while (0 <= s && s < N && m[s] > target) {
		--s;
	}
	
	if (s == N) {
		return mem[N - 1];
	}
	else if (s == -1) {
		return target * N;
	}
	return mem[s] + target * (N - s - 1);
}

ll BinarySearchByNumber(ll s, ll e, ll target) {
	while (s < e) {
		ll mid = (s + e) / 2;
		ll cal = BinarySearchByIndex(0, N, mid);
		if (target == cal) {
			ans = { cal, mid };
			return 1;
		}
		else if (target > cal) {
			if (ans.first < cal) {
				ans = { cal, mid };
			}
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	return - 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	mem[0] = m[0];
	for (ll i = 1; i < N; i++) {
		mem[i] = mem[i - 1] + m[i];
	}

	cin >> M;

	BinarySearchByNumber(0, M, M);

	cout << min(ans.second, m[N-1]);

	return 0;
}
