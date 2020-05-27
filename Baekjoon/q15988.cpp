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

ll T, N, ans;
ll mem[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	mem[1] = 1;
	mem[2] = 2;
	mem[3] = 4;
	for (ll i = 4; i < 1000001; i++) {
		mem[i] = mem[i - 1] + mem[i - 2] + mem[i - 3];
		mem[i] %= 1000000009;
	}

	cin >> T;
	for (ll i = 0; i < T; i++) {
		cin >> N;
		cout << mem[N] << '\n';
	}

	return 0;
}
