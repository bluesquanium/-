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

ll N, Q, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N);
	ll cnt[2] = { 0 };
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		cnt[m[i]]++;
	}
	for (ll i = 0; i < Q; i++) {
		ll type, num;
		cin >> type >> num;
		if (type == 1) {
			num--;
			if (m[num] == 1) {
				m[num] = 0;
				cnt[0]++;
				cnt[1]--;
			}
			else {
				m[num] = 1;
				cnt[0]--;
				cnt[1]++;
			}
		}
		else {
			if (num <= cnt[1]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}

	return 0;
}
