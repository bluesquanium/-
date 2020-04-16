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

#define MOD 1000000000

ll N, M, ans;
vector<ll> m[2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m[0].resize(12, 1); m[1].resize(12, 0);
	m[0][0] = m[0][1] = m[0][11] = 0;
	for (int n = 0; n < N - 1; n++) {
		for (int i = 1; i <= 10; i++) {
			m[(n+1) % 2][i] = (m[n % 2][i - 1] + m[n % 2][i + 1]) % MOD;
		}
	}

	for (int i = 1; i <= 10; i++) {
		ans = (ans + m[(N+1)%2][i]) % MOD;
	}

	cout << ans;

	return 0;
}
