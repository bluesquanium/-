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

ll N, ans, temp;
vector<ll> m;
vector<pll> st;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	st.push_back({ 0, m[0] });
	for (ll i = 1; i < N; i++) {
		if (st.back().second < m[i]) {
			st.push_back({ i, m[i] });
		}
		else if (st.back().second > m[i]) {
			ll prevIdx;
			while (!st.empty()) {
				pll cur = st.back();
				if (cur.second < m[i]) {
					break;
				}
				st.pop_back();
				
				ll wide = cur.second * (i - cur.first);
				ans = max(ans, wide);

				prevIdx = cur.first;
			}
			st.push_back({ prevIdx, m[i] });
		}
	}
	while (!st.empty()) {
		pll cur = st.back(); st.pop_back();
		ll wide = cur.second * (N - cur.first);
		ans = max(ans, wide);
	}

	cout << ans;

	return 0;
}
