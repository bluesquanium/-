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
vector<ll> m;
vector<ll> b;

vector<ll> mem;
ll cal(ll memIdx, ll curMIdx) {
	ll prevMIdx = mem[memIdx];
	ll prevVal = m[prevMIdx];
	
	return prevVal + curMIdx - prevMIdx;
}
ll binarySearch(ll curIdx) {
	ll val = m[curIdx];
	ll l = 0, r = mem.size();
	while (l < r) {
		ll mid = (l + r) / 2;
		if (cal(mid, curIdx) <= val) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}

	return l;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N + 2);
	b.resize(K + 2);
	m[0] = -INF;
	for (ll i = 1; i <= N; i++) {
		cin >> m[i];
	}
	m[N + 1] = INF;
	b[0] = 0;
	for (ll i = 1; i <= K; i++) {
		cin >> b[i];
	}
	b[K + 1] = N + 1;

	ll bcur = 1, prev = m[0];
	for (ll i = 1; i <= N; i++) {
		if (b[bcur] != i) {
			prev = prev + 1;
		}
		else {
			if (prev >= m[i]) {
				ans = -1;
				break;
			}
			prev = m[i];
			bcur++;
		}
	}

	if (ans != -1) {
		for (ll i = 1; i < K + 2; i++) {
			mem.clear();
			ll le = b[i - 1], ri = b[i];

			for (ll j = le + 1; j < ri; j++) {
				if (m[le] + j - le <= m[j] && m[j] <= m[ri] - (ri - j)) {
					ll memIdx = binarySearch(j);
					if (memIdx >= mem.size()) {
						mem.push_back(j);
					}
					else {
						mem[memIdx] = j;
					}
				}
			}

			ans += (ri - le - 1) - mem.size();
		}
	}

	cout << ans;

	return 0;
}
