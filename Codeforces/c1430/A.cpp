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
ll mem[1001][3]; // 3 5 7

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	mem[3][0] = 1; mem[3][1] = 0; mem[3][2] = 0;
	mem[5][0] = 0; mem[5][1] = 1; mem[5][2] = 0;
	mem[6][0] = 2; mem[6][1] = 0; mem[6][2] = 0;
	mem[7][0] = 0; mem[7][1] = 0; mem[7][2] = 1;
	mem[8][0] = 1; mem[8][1] = 1; mem[8][2] = 0;
	for (ll i = 1; i * 3 <= 1000; i++) {
		mem[i * 3][0] = i;
		if (i * 3 + 7 <= 1000) {
			mem[i * 3 + 7][0] = i;
			mem[i * 3 + 7][2] = 1;
		}
		if (i * 3 + 8 <= 1000) {
			mem[i * 3 + 8][0] = i + 1;
			mem[i * 3 + 8][1] = 1;
		}
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;

		if (N == 1 || N == 2 || N == 4) {
			cout << "-1\n";
		}
		else {
			cout << mem[N][0] << ' ' << mem[N][1] << ' ' << mem[N][2] << '\n';
		}
	}

	return 0;
}
