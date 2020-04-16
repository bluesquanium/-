#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define MOD 998244353
using namespace std;

ll N, M, ans;
vector<ll> pow10;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	pow10.resize(N);
	pow10[0] = 1;
	for (int i = 1; i < N; i++) {
		pow10[i] = (pow10[i - 1] * 10) % MOD;
	}
	for (int i = 1; i < N; i++) {
		ans = 18 * pow10[N - i];
		ans %= MOD;
		ans += (N - i - 1) * 81 * pow10[N - i - 1];
		ans %= MOD;
		cout << ans << " ";
	}
	cout << "10";

	return 0;
}
