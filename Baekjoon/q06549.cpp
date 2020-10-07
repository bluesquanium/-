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

ll N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		ans = 0;
		cin >> N;
		if (N == 0) {
			break;
		}

		vector<pll> st;
		m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			st.push_back({ m[i], i });
			while (st.size() >= 2) {
				pll cur = st.back(); st.pop_back();
				pll prev = st.back(); st.pop_back();
				if (prev.first < cur.first) {
					st.push_back(prev);
					st.push_back(cur);
					break;
				}
				else if (prev.first == cur.first) {
					st.push_back(prev);
					break;
				}
				else {
					ans = max(ans, (i - prev.second) * prev.first);

					st.push_back({ cur.first, prev.second });
				}
			}
		}
		while (!st.empty()) {
			pll cur = st.back(); st.pop_back();
			
			ans = max(ans, (N - cur.second) * cur.first);
		}

		cout << ans << '\n';
	}

	return 0;
}
