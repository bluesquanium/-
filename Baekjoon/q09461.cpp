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

ll T, N, M, ans;
ll mem[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	mem[1] = mem[2] = mem[3] = 1;
	mem[4] = mem[5] = 2;
	for (int i = 6; i <= 100; i++) {
		mem[i] = mem[i - 1] + mem[i - 5];
	}

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;

		cout << mem[N] << '\n';
	}

	return 0;
}
