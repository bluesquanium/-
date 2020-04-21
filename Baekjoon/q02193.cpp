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
ll mem[91][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	mem[1][1] = 1;
	mem[1][0] = 0;
	for (int i = 2; i <= N; i++) {
		mem[i][1] = mem[i - 1][0];
		mem[i][0] = mem[i - 1][0] + mem[i - 1][1];
	}

	cout << mem[N][0] + mem[N][1];

	return 0;
}
