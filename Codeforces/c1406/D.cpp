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

ll N, Q, ans, temp, l, r, x, deltaPlus, base;
vector<ll> m, mem;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N); mem.resize(N - 1, 0);
	deltaPlus = 0;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		if (i != 0) {
			mem[i - 1] = m[i] - m[i - 1];
			if (mem[i - 1] > 0) {
				deltaPlus += mem[i - 1];
			}
		}
	}
	base = m[0];
	if (base + deltaPlus > 0) {
		ans = (base + deltaPlus + 1) / 2;
	}
	else {
		ans = (base + deltaPlus) / 2;
	}
	cout << ans << '\n';

	cin >> Q;
	for (ll i = 0; i < Q; i++) {
		cin >> l >> r >> x;
		l--; r--;
		if (l == 0) {
			base += x;
		}
		if (l >= 1) {
			if (mem[l - 1] > 0 || mem[l - 1] + x > 0) {
				if (mem[l - 1] > 0 && mem[l - 1] + x > 0) {
					deltaPlus += x;
				}
				else if (mem[l - 1] > 0) {
					deltaPlus -= mem[l - 1];
				}
				else if (mem[l - 1] + x > 0) {
					deltaPlus += mem[l - 1] + x;
				}
			}

			mem[l - 1] += x;
		}
		if (r <= N - 2) {
			if (mem[r] > 0 || mem[r] - x > 0) {
				if (mem[r] > 0 && mem[r] - x > 0) {
					deltaPlus -= x;
				}
				else if (mem[r] > 0) {
					deltaPlus -= mem[r];
				}
				else if (mem[r] - x > 0) {
					deltaPlus += mem[r] - x;
				}
			}

			mem[r] -= x;
		}

		if (base + deltaPlus > 0) {
			ans = (base + deltaPlus + 1) / 2;
		}
		else {
			ans = (base + deltaPlus) / 2;
		}
		cout << ans << '\n';
	}

	return 0;
}
