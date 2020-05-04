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

#define MOD 998244353

ll N, M, L, R;
pll ans = { 1, 0 };
vector<ll> m;

pll mem[61];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> L >> R;

	if (L == R) {
		cout << 1;
		return 0;
	}

	ll cur = 60, mul = 1;
	mem[1] = { (R - L + 1) / 2 + (R - L + 1) % 2, (R - L + 1) / 2};
	for (ll i = 2; i < 61; i++) {
		mul *= 2;
		mem[i] = { (mem[i - 1].first * mem[i - 1].first + mem[i - 1].second * mem[i - 1].second) % MOD, (mem[i - 1].second * mem[i - 1].first * 2) % MOD };
	}

	ll num = N * M;
	while (num) {
		if (num >= mul) {
			num -= mul;
			ans = { (ans.first * mem[cur].first + ans.second * mem[cur].second) % MOD, (ans.first * mem[cur].second + ans.second * mem[cur].first) % MOD };
		}
		else {
			mul /= 2;
			cur--;
		}
	}

	if ((N * M) % 2 == 1) {
		cout << (ans.first + ans.second) % MOD;
	} else {
		cout << ans.first % MOD;
	}

	return 0;
}
