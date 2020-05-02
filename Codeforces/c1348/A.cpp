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

ll T, N, a, b, ans;
vector<ll> m;
ll pow2[31];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll num = 2;
	for (ll i = 1; i <= 30; i++) {
		pow2[i] = num;
		num *= 2;
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		a = b = 0;
		cin >> N;

		a = pow2[N];
		for (ll i = 1; i < N / 2; i++) {
			a += pow2[i];
		}
		for (ll i = N / 2; i < N; i++) {
			b += pow2[i];
		}

		cout << abs(a - b) << '\n';
	}

	return 0;
}
