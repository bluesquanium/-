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

ll N, R, ans, temp;
ll m[100001][3];
ll mem[100001];
ll maxi[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> R >> N;
	m[0][0] = 0; m[0][1] = 1; m[0][2] = 1;
	for (ll i = 1; i <= N; i++) {
		cin >> m[i][0] >> m[i][1] >> m[i][2];
	}

	memset(mem, -1, sizeof(ll) * 100001);
	mem[0] = 0;
	maxi[0] = 0;
	mem[1] = abs(m[1][1] - 1) + abs(m[1][2] - 1) > m[1][0] ? -1 : 1;
	maxi[1] = max(maxi[0], mem[1]);
	ans = max(mem[0], mem[1]);
	for (ll i = 2; i <= N; i++) {
		for (ll j = i - 1; j >= 0; j--) {
			if (m[i][0] - m[j][0] >= 1000) {
				mem[i] = max(mem[i], maxi[j] + 1);
				break;
			}
			if (abs(m[i][1] - m[j][1]) + abs(m[i][2] - m[j][2]) <= m[i][0] - m[j][0]) {
				if (mem[j] != -1) {
					mem[i] = max(mem[i], mem[j] + 1);
				}
			}
		}
		ans = max(ans, mem[i]);
		maxi[i] = max(mem[i], maxi[i-1]);
	}

	cout << ans;

	return 0;
}
