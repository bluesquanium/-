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
		map<ll, ll> check;
		ll sum = 0;

		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			sum += m[i];
			if (check.count(m[i]) == 0) {
				check[m[i]] = 1;
			}
			else {
				check[m[i]]++;
			}
		}

		vector<ll> st;
		if (check.count(sum) != 0) {
			ans = 1;
		}
		else {
			ll found = 0;
			ans = 1;
			st.push_back(sum);
			while (!st.empty()) {
				if (found + st.size() >= N) {
					ans = 0;
					break;
				}

				ll cur = st.back(); st.pop_back();
				ll a[2] = { cur / 2, cur / 2 + (cur % 2) };

				for (ll i = 0; i < 2; i++) {
					if (check.count(a[i]) && check[a[i]] > 0) {
						check[a[i]]--;
						found++;
					}
					else {
						if (a[i] == 1) {
							ans = 0;
							break;
						}
						st.push_back(a[i]);
					}
				}

				if (ans == 0) {
					break;
				}
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
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
