#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, M, K, a, b;
vector<int> m, sale, mem;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;

	m.resize(N+1);
	sale.resize(K + 1);
	mem.resize(K+1);

	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	m.resize(K+1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (a <= K) {
			if (sale[a] < b) {
				sale[a] = b;
			}
		}
	}

	for (int i = 1; i <= K; i++) {
		m[i] = m[i-1] + m[i];

		mem[i] = m[i];
		if (sale[i] != 0) {
			mem[i] -= m[sale[i]];
		}
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= i; j++) {
			mem[i] = min(mem[i], mem[i - j] + (m[i] - m[i - j + sale[j]]));
		}

	}

	cout << mem[K];

	return 0;
}
