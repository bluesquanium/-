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
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		if (N == 1) {
			if (m[0] == 0) {
				cout << "1 2";
			}
			else {
				cout << "2 1";
			}
		}
		else {
			if (m[N - 1] == 0) {
				for (ll i = 0; i < N + 1; i++) {
					cout << i + 1 << ' ';
				}
			}
			else if (m[0] == 1) {
				cout << N + 1 << ' ';
				for (ll i = 0; i < N; i++) {
					cout << i + 1 << ' ';
				}
			}
			else {
				ll tp = -1; // turningPoint
				for (ll i = 1; i < N; i++) {
					if (m[i - 1] == 0 && m[i] == 1) {
						tp = i - 1;
						break;
					}
				}
				if (tp == -1) {
					cout << "-1";
				}
				else {
					for (ll i = 0; i < N; i++) {
						if (i == tp) {
							cout << i + 1 << ' ' << N + 1 << ' ';
						}
						else {
							cout << i + 1 << ' ';
						}
					}
				}
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
