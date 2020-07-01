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

ll T, N, A, B, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> A >> B >> N;
		
		if (A > N || B > N) {
			ans = 0;
		}
		else {
			ans = 1;
			while (A + B <= N) {
				if (A < B) {
					A += B;
				}
				else {
					B += A;
				}
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
