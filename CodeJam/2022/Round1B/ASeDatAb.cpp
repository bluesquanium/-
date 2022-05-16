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
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cout << "01010101\n";

		ll num, cnt = 1;
		while (1) {
			cin >> num;
			if (num == 0) {
				break;
			}
			if (cnt == 300 || num == -1) {
				return 0;
			}

			string s = "00000000";
			ll tcnt = 0;
			while (tcnt != num) {
				ll pos = rand() % 8;
				if (s[pos] == '0') {
					s[pos] = '1';
					tcnt++;
				}
			}
			cout << s << '\n';

			
			cnt++;
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
