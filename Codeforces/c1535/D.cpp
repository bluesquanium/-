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

ll T, K, N, M, Q, ans, temp;
vector<ll> m;

ll pow2[19] = {
	1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ans = 0;

	vector<ll> mem;
	string s, s2;
	cin >> K;
	cin >> s;
	ll size = s.size();
	s2.resize(size + 1);
	mem.resize(size + 1, 0);
	for (ll i = 1; i <= size; i++) {
		s2[i] = s[size - i];
	}

	ll num = pow2[K] / 2;
	ll idx = size;
	for (ll i = 0; i < num; i++) {
		if (s2[idx - i] == '?') {
			mem[idx - i] = 2;
		}
		else {
			mem[idx - i] = 1;
		}
	}
	idx -= num;
	num /= 2;

	while (num) {
		for (ll i = 0; i < num; i++) {
			ll curidx = idx - i;
			if (s2[curidx] == '?') {
				mem[curidx] = mem[curidx * 2] + mem[curidx * 2 + 1];
			}
			else if (s2[curidx] == '0') {
				mem[curidx] = mem[curidx * 2 + 1];
			}
			else {
				mem[curidx] = mem[curidx * 2];
			}
		}
		idx -= num;
		num /= 2;
	}

	cin >> Q;
	for (ll q = 0; q < Q; q++) {
		ll idx;
		char c;
		cin >> idx >> c;
		idx = s.size() - idx + 1;
		s2[idx] = c;

		if (idx * 2 <= size) {
			ll newval;
			if (c == '?') {
				newval = mem[idx * 2] + mem[idx * 2 + 1];
			}
			else if (c == '0') {
				newval = mem[idx * 2 + 1];
			}
			else {
				newval = mem[idx * 2];
			}
			mem[idx] = newval;
		}
		else {
			if (c == '?') {
				mem[idx] = 2;
			}
			else {
				mem[idx] = 1;
			}
		}

		ll cur = idx / 2;
		while (cur) {
			if (s2[cur] == '?') {
				mem[cur] = mem[cur * 2] + mem[cur * 2 + 1];
			}
			else if (s2[cur] == '0') {
				mem[cur] = mem[cur * 2 + 1];
			}
			else {
				mem[cur] = mem[cur * 2];
			}

			cur /= 2;
		}

		cout << mem[1] << '\n';
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
