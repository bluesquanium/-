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
vector<ll> mem[200001];
vector<ll> sums[200001];
set<ll> u;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 1; i <= N; i++) {
			mem[i].clear();
			sums[i].clear();
			u.clear();
		}
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			u.insert(m[i]);
		}
		for (ll i = 0; i < N; i++) {
			cin >> temp;
			mem[m[i]].push_back(temp);
		}

		ll maxStudent = 0;
		for (auto iter = u.begin(); iter != u.end(); iter++) {
			ll uNum = *iter;
			sort(mem[uNum].rbegin(), mem[uNum].rend());
			maxStudent = max(maxStudent, (ll)mem[uNum].size());

			ll sum = 0;
			for (ll i = 0; i < mem[uNum].size(); i++) {
				sum += mem[uNum][i];
				sums[uNum].push_back(sum);
			}
		}

		for (ll k = 1; k <= N; k++) {
			if (maxStudent < k) {
				cout << "0 ";
			}
			else {
				ll sum = 0;
				for (auto iter = u.begin(); iter != u.end(); iter++) {
					ll uNum = *iter;
					ll numStudent = mem[uNum].size();
					if (numStudent >= k) {
						sum += sums[uNum][numStudent - (numStudent % k) - 1];
					}
				}

				cout << sum << ' ';
			}
		}
		cout << '\n';
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
