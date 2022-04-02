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

ll N, M, ans, temp;
vector<ll> a, b;

ll mem[5000][5000];
ll sums[5000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	a.resize(N); b.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < N; i++) {
		cin >> b[i];
	}

	sums[0] = a[0] * b[0];
	for (ll i = 1; i < N; i++) {
		sums[i] = sums[i - 1] + a[i] * b[i];
	}
	for (ll i = 1; i < N; i++) {
		ll sum = 0;
		for (ll j = i; j < N; j++) {
			sum += a[N - (j - i) - 1] * b[j];
		}
		mem[i][N - 1] = sum;
	}

	ans = sums[N - 1];
	for (ll i = 0; i < N; i++) {
		ll sum = 0;
		for (ll j = 0; j <= i; j++) {
			sum += a[i - j] * b[j];
		}
		mem[0][i] = sum;

		ans = max(ans, sum + sums[N - 1] - sums[i]);
	}

	for (ll i = 1; i < N; i++) {
		for (ll j = i; j < N; j++) {
			if (j == N - 1) {
				ans = max(ans, mem[i][j] + sums[i - 1]);
			}
			else {
				ll sum = mem[i - 1][j + 1];
				sum -= b[i - 1] * a[j + 1] + a[i - 1] * b[j + 1];
				mem[i][j] = sum;

				ans = max(ans, sum + sums[N - 1] - sums[j] + sums[i - 1]);
			}
		}
	}

	cout << ans;

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
