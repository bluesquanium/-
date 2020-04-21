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

#define MOD 15746
using namespace std;

ll N, M, ans;
ll mem[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	mem[0] = mem[1] = 1;
	for (int i = 2; i <= N; i++) {
		mem[i] = (mem[i - 1] + mem[i - 2]) % MOD;
	}

	cout << mem[N];

	return 0;
}
