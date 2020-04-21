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
ll mem[1000][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		for (int j = i - 1; j >= 0; j--) {
			if (m[i] > m[j]) {
				mem[i][0] = max(mem[i][0], mem[j][0]);
			}
		}
		mem[i][0]++;
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if (m[i] > m[j]) {
				mem[i][1] = max(mem[i][1], mem[j][1]);
			}
		}
		mem[i][1]++;
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, mem[i][0] + mem[i][1] - 1);
	}

	cout << ans;

	return 0;
}
