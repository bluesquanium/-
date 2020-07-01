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

ll N, P;
ll mem[4001];
vector<ll> m;
vector<ll> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll maxi = 1;
	cin >> N >> P;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		maxi = max(maxi, m[i]);
		mem[m[i]]++;
	}
	for (ll i = 1; i <= 4000; i++) {
		mem[i] += mem[i - 1];
	}

	for (ll base = 1; base <= 2000; base++) {
		if (base >= maxi) {
			if (P > N) {
				ans.push_back(base);
			}
		}
		else {
			ll check = 1;
			for (ll cur = 0; cur < N; cur++) {
				if ((mem[base + cur] - cur) % P == 0) {
					check = 0;
					break;
				}
			}
			if (check) {
				ans.push_back(base);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	} cout << '\n';

	return 0;
}
