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
		cin >> N;
		m.clear(); m.resize(N);
		ll maxi = -1, maxCnt = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] > maxi) {
				maxi = m[i];
				maxCnt = 1;
			}
			else if (m[i] == maxi) {
				maxCnt++;
			}
		}

		if (maxCnt == N) {
			cout << N << '\n';
		}
		else {
			cout << "1\n";
		}
	}

	return 0;
}
