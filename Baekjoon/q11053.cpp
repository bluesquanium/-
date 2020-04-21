#include <iostream>
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

ll N, M, ans;
vector<ll> m;
ll mem[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		ll maxi = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (m[j] < m[i]) {
				maxi = max(maxi, mem[j]);
			}
		}
		mem[i] = maxi + 1;
		ans = max(ans, mem[i]);
	}

	cout << ans;

	return 0;
}
