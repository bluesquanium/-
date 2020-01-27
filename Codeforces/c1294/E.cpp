#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define MAXHALF 500000000
using namespace std;

ll N, M, ans;
vector< vector<int> > m, mem;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	m.resize(N);
	mem.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M);
		mem[i].resize(M, 0);
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> m[i][j];
			if ((m[i][j] - (j + 1)) % M == 0) {
				if (-N < (i - (m[i][j] - (j + 1)) / M) && (i - (m[i][j] - (j + 1)) / M) < N) {
					mem[((i - (m[i][j] - (j + 1)) / M) + N) % N][j]++;
				}
			}
		}
	}

	for (ll j = 0; j < M; j++) {
		int mini = N;
		for (ll i = 0; i < N; i++) {
			if (mini > (N - mem[i][j]) + i) {
				mini = (N - mem[i][j]) + i;
			}
		}
		ans += mini;
	}

	cout << ans << '\n';

	return 0;
}
