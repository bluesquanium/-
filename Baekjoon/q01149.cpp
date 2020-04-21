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

ll N, M;
ll mem[1000][3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> mem[0][0] >> mem[0][1] >> mem[0][2];
	for (int i = 1; i < N; i++) {
		cin >> mem[i][0] >> mem[i][1] >> mem[i][2];
		mem[i][0] += min(mem[i - 1][1], mem[i - 1][2]);
		mem[i][1] += min(mem[i - 1][0], mem[i - 1][2]);
		mem[i][2] += min(mem[i - 1][0], mem[i - 1][1]);
	}

	cout << min(min(mem[N - 1][0], mem[N - 1][1]), mem[N-1][2]);
	return 0;
}
