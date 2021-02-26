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
//vector<pll> targets;
ll cnt[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		priority_queue< pll, vector<pll>, less<pll> > pq;

		ans = 0;
		cin >> N;
		for (ll i = 0; i <= N; i++) {
			cnt[i] = 0;
		}
		//targets.clear();
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (i != 0 && m[i] == m[i - 1]) {
				cnt[m[i]]++;
			}
		}
		for (ll i = 1; i <= N; i++) {
			if (cnt[i] != 0) {
				pq.push({ cnt[i], i });
				//targets.push_back({ cnt[i], i });
			}
		}
		
		//임시
		for (ll i = 0; i <= N; i++) {
			cnt[i] = 0;
		}
		for (ll i = 0; i < N; i++) {
			cnt[m[i]]++;
		}
		ll maxi = 0, maxi_val = 0;
		for (ll i = 1; i <= N; i++) {
			if (cnt[i] > maxi) {
				maxi = cnt[i];
				maxi_val = i;
			}
		}
		if (maxi > (N + 1) / 2) {
			ans = -1;
		}
		// \임시
		//sort(targets.rbegin(), targets.rend());

		if (ans == 0) {
			ll f = m[0], e = m[N - 1];
			while (!pq.empty()) {
				pll cur = pq.top(); pq.pop();
				if (f != cur.second || e != cur.second) {
					if (f != cur.second) {
						f = cur.second;
					}
					else {
						e = cur.second;
					}
					cur.first--;
					ans++;
				}
				else {
					if (!pq.empty()) {
						pll cur2 = pq.top(); pq.pop();
						if (f != cur2.second) {
							f = cur2.second;
						}
						else if (e != cur2.second) {
							e = cur2.second;
						}
						else {
							ans = -2;
							break;
						}
						cur2.first--;
						if (cur2.first != 0) {
							pq.push(cur2);
						}
						ans++;
					}
					else {
						ans += 2;
						cur.first--;
					}
				}

				if (cur.first != 0) {
					pq.push(cur);
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
