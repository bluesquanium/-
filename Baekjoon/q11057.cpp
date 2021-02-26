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

#define MOD 10007

ll N, M, ans, temp;
vector<ll> m;
ll mem[1001][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	ans = 10;
	for (ll i = 0; i < 10; i++) {
		mem[1][i] = 1;
	}
	for (ll i = 2; i <= N; i++) {
		for (ll j = 1; j <= 9; j++) {
			for (ll k = j; k <= 9; k++) {
				mem[i][j] += mem[i - 1][k];
				mem[i][j] %= MOD;
			}
		}
		for (ll j = 1; j <= 9; j++) {
			ans += mem[i][j];
			ans %= MOD;
		}
	}

	cout << ans;

	return 0;
}
