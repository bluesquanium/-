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

ll T, N, L, R, ans;
vector<ll> le;
vector<ll> ri;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> L >> R;
		le.clear(); le.resize(L);
		ri.clear(); ri.resize(R);
		for (ll i = 0; i < L; i++) {
			cin >> le[i];
		}
		for (ll i = 0; i < R; i++) {
			cin >> ri[i];
		}
		sort(le.begin(), le.end());
		sort(ri.begin(), ri.end());

		ll lCur = 0, rCur = 0;
		vector<ll> tl, tr;
		while (lCur < L || rCur < R) {
			if (lCur >= L) {
				tr.push_back(ri[rCur]);
				rCur++;
			}
			else if (rCur >= R) {
				tl.push_back(le[lCur]);
				lCur++;
			}
			else if (le[lCur] < ri[rCur]) {
				tl.push_back(le[lCur]);
				lCur++;
			}
			else if (le[lCur] > ri[rCur]) {
				tr.push_back(ri[rCur]);
				rCur++;
			}
			else {
				lCur++;
				rCur++;
			}
		}
		le = tl;
		ri = tr;

		if (L < R) {
			vector<ll> temp;
			temp = le;
			le = ri;
			ri = temp;
		}

		ll count = (le.size() - ri.size()) / 2;
		for (ll i = 1; i < le.size(); i++) {
			if (count == 0) {
				break;
			}

			if (le[i - 1] == le[i]) {
				count--;
				i++;
			}
		}

		cout << (le.size() + ri.size()) / 2 + count << '\n';
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
