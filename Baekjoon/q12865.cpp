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

ll N, K, ans;
vector<pll> m;
ll mem[100][100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}

	for (int i = m[0].first; i <= K; i++) {
		mem[0][i] = m[0].second;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < m[i].first; j++) {
			mem[i][j] = mem[i - 1][j];
		}
		for (int j = m[i].first; j <= K; j++) {
			mem[i][j] = max(m[i].second + mem[i - 1][j - m[i].first], mem[i-1][j]);
		}
	}

	cout << mem[N - 1][K];

	return 0;
}
