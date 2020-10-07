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

ll Gcd(ll x, ll y) {
	return y ? Gcd(y, x%y) : x;
}

ll Lcm(ll x, ll y) {
	return x * y / Gcd(x, y);
}

ll T, N, M, A, B, ans, temp;
ll m[50][50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M >> A >> B;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				m[i][j] = 0;
			}
		}
		
		ll gcd = Gcd(A, B);
		ll ra = A / gcd, rb = B / gcd;
		ll base = 0, rbCnt = 0;
		if ((N % rb == 0 && M % ra == 0) &&
			(N / rb == M / ra)
		    ) {
			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < A; j++) {
					m[i][(base + j) % M] = 1;
				}
				rbCnt = (rbCnt + 1) % rb;
				if (rbCnt == 0) {
					base += ra;
				}
			}

			cout << "YES\n";
			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < M; j++) {
					cout << m[i][j];
				}
				cout << '\n';
			}
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
