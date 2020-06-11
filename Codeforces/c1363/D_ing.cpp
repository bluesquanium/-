#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, K, t;
vector< vector<ll> > m;
string q;
ll ans[1000];

ll SendQuery(ll s, ll e) {
	q = "? ";
	q += e - s + '0';
	q += " ";
	for (ll i = s; i < e; i++) {
		q += i + '1';
		q += " ";
	}
	cout << q; q.clear();
	cout << "\n\n";
	cin >> t;
	return t;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		m.clear(); m.resize(N);
		for (ll i = 0; i < K; i++) {
			cin >> t;
			m[i].resize(t);
			for (ll j = 0; j < t; j++) {
				cin >> m[i][j];
			}
		}

		q = "? ";
		q += N + '0';
		q += " ";
		for (ll i = 1; i <= N; i++) {
			q += i + '0';
			q += " ";
		}
		cout << q; q.clear();
		cout << "\n\n";
		ll maxi, maxi_idx;
		cin >> maxi;
		ll s = 0, e = N;
		while (s < e) {
			if (e - s == 1) {
				maxi_idx = s;
				break;
			}
			ll mid = (s + e) / 2;
			ll t = SendQuery(s, mid);
			if (maxi == t) {
				e = mid;
			}
			else {
				s = mid;
			}
		}

		maxi_idx++;

		for (ll i = 0; i < K; i++) {
			bool check = false;
			for (ll j = 0; j < m[i].size(); j++) {
				if (m[i][j] == maxi_idx) {
					check = true;
					break;
				}
			}

			if (check) {
				ll mem[1001];
				memset(mem, 0, sizeof(ll) * 1001);
				for (ll j = 0; j < m[i].size(); j++) {
					mem[m[i][j]] = 1;
				}
				vector<ll> mem2;
				for (ll j = 1; j <= N; j++) {
					if (mem[j] == 0) {
						mem2.push_back(j);
					}
				}
				q = "? ";
				q += mem2.size() + '0';
				q += " ";
				for (ll j = 0; j < mem2.size(); j++) {
					q += mem2[j] + '0';
					q += " ";
				}
				cout << q; q.clear();
				cout << "\n\n";
				cin >> t;
				ans[i] = t;
			}
			else {
				ans[i] = maxi;
			}
		}

		q = "! ";
		for (ll i = 0; i < K; i++) {
			q += ans[i] + '0';
			q += " ";
		}
		cout << q << '\n';
	}

	return 0;
}
