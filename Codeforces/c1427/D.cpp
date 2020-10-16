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

ll N, M, temp;
vector<ll> m;
vector< vector<ll> > ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> m[i];
	}

	for (ll i = 1; i <= N; i++) {
		vector<ll> segs;
		ll cnt = 0;

		if (i % 2 && i == N) {
			continue;
		}

		if (i % 2) { // odd
			ll j = 1;
			for (; j < i; j++) {
				segs.push_back(1);
			}
			for (; j <= N; j++) {
				cnt++;
				if (m[j] == i) {
					segs.push_back(cnt);
					j++;
					break;
				}
			}
			cnt = 0;
			for (; j <= N; j++) {
				cnt++;
			}
			if (cnt) {
				segs.push_back(cnt);
			}

			if (segs.size() > 1) {
				ans.push_back(segs);

				vector<ll> temp;
				temp.resize(N + 1);
				for (ll j = 1; j <= N; j++) {
					temp[j] = m[j];
				}
				cnt = 0;
				for (ll j = 0; j < segs.size(); j++) {
					ll base = N - cnt - (segs[j] - 1);
					for (ll k = 0; k < segs[j]; k++) {
						m[base + k] = temp[cnt + 1];
						cnt++;
					}
				}
			}
		}
		else {
			ll j = 1;
			for (; j < i; j++) {
				segs.push_back(1);
			}
			for (; j <= N; j++) {
				cnt++;
				if (m[N - j + 1] == i) {
					segs.push_back(cnt);
					j++;
					break;
				}
			}
			cnt = 0;
			for (; j <= N; j++) {
				cnt++;
			}
			if (cnt) {
				segs.push_back(cnt);
			}

			if (segs.size() > 1) {
				vector<ll> temp_segs;
				for (ll j = segs.size() - 1; j >= 0; j--) {
					temp_segs.push_back(segs[j]);
				}
				ans.push_back(temp_segs);

				vector<ll> temp;
				temp.resize(N + 1);
				for (ll i = 1; i <= N; i++) {
					temp[i] = m[i];
				}
				cnt = N;
				for (ll j = 0; j < segs.size(); j++) {
					ll base = cnt - (segs[j] - 1);
					for (ll k = 0; k < segs[j]; k++) {
						m[N - cnt + 1] = temp[base + k];
						cnt--;
					}
				}
			}
		}	
	}

	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		vector<ll> v = ans[i];
		cout << ans[i].size() << ' ';
		for (auto val : ans[i]) {
			cout << val << ' ';
		}
		cout << '\n';
	}

	return 0;
}
