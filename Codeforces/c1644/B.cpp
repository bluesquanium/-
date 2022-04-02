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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		
		if (N == 3) {
			cout << "3 2 1\n";
			cout << "1 3 2\n";
			cout << "3 1 2\n";
		}
		else {
			ll s = 0;
			for (ll i = 0; i < N; i++) {
				for (ll j = N; j > 0; j--) {
					ll num = (j - i + N) % N;
					if (num == 0) {
						num = N;
					}
					cout << num << ' ';
				}
				cout << '\n';
				s++;
			}
		}
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
