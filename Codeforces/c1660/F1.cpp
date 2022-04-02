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

ll mem[3000][4]; // 0: +, 1: -, 2: --, 3: pos trans -

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		string m;
		cin >> N;
		cin >> m;

		ll cntp = 0, cntm = 0, cntmm = 0, posTrans = 0;
		for (ll i = 0; i < N; i++) {
			if (m[i] == '-') {
				cntm++;
				if (posTrans == 1) {
					cntmm++;
				}
				posTrans = !posTrans;
			}
			else {
				cntp++;
				posTrans = 0;
			}

			mem[i][0] = cntp;
			mem[i][1] = cntm;
			mem[i][2] = posTrans;
		}

		/*
		for (ll i = 2; i < N; i++) {
			ll cntp = mem[i - 1][0];
			ll cntm = mem[i - 1][1];
			ll cntmm = mem[i - 1][2];
			ll posTrans = mem[i - 1][3];

			ll base = 0;
			for (ll j = i; j < N; j++) {
				if (m[i] == '-') {
					cntm--;
				}
				else {
					cntp--;
				}
			}
		}
		*/

		for (ll start = 0; start < N; start++) {
			cntp = 0; cntm = 0; cntmm = 0; posTrans = 0;
			for (ll i = start; i < N; i++) {
				if (m[i] == '-') {
					cntm++;
					if (posTrans == 1) {
						cntmm++;
					}
					posTrans = !posTrans;
				}
				else {
					cntp++;
					posTrans = 0;
				}

				if (cntm == cntp) {
					ans++;
				}
				else if (cntm - cntp >= 0 && (cntm - cntp) % 3 == 0 && cntmm >= (cntm - cntp) / 3) {
					ans++;
				}
			}
		}

		cout << ans << '\n';
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
