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
ll m[2][100001];
ll mem[2][100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> m[0][i];
		}
		for (ll i = 0; i < N; i++) {
			cin >> m[1][i];
		}

		mem[0][1] = m[0][0];
		mem[1][1] = m[1][0];
		mem[0][2] = mem[1][1] + m[0][1];
		mem[1][2] = mem[0][1] + m[1][1];
		for (ll i = 2; i <= N; i++) {
			mem[0][i] = m[0][i - 1] + max(mem[1][i - 1], mem[1][i - 2]);
			mem[1][i] = m[1][i - 1] + max(mem[0][i - 1], mem[0][i - 2]);
		}

		cout << max(mem[0][N], mem[1][N]) << '\n';
	}

	return 0;
}
