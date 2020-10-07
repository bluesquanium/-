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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		//ans = 1;
		cin >> N;
		m.clear(); m.resize(N);
		ll oddNum = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if(m[i] % 2) {
				oddNum++;
			}
		}
		
		ans = 0;
		if(oddNum % 2 == 0) {
			ans = 1;
		} else {
			sort(m.begin(), m.end());
			for(ll i = 1; i < N; i++) {
				if(m[i] - m[i - 1] == 1) {
					ans = 1;
					break;
				}
			}
		}
		
		if(ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
