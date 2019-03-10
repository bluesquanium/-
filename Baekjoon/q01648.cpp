#include <iostream>
#include <cstring>
using namespace std;

int N, M, ans;
int ** m;

int Dfs(int cur, int bitmask) {
	if (cur == N*M && bitmask == 0) {
		return 1;
	}

	if (cur / M < N) {
		int &result = m[cur][bitmask];
		if (result != -1) {
			return result;
		}

		if ((bitmask&1) == 1) { // or bitmask & 1
			result = Dfs(cur + 1, (bitmask >> 1));
		}
		else {
			result = Dfs(cur + 1, (bitmask >> 1) + (1 << (M - 1)));
			if (cur%M + 1 < M) {
				if (((bitmask >> 1) & 1) == 0) {
					result += Dfs(cur + 2, (bitmask >> 2));
				}
			}
		}
		return result %= 9901;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;

	m = new int*[N*M];
	for (int i = 0; i < N*M; i++) {
		m[i] = new int[1<<M];
		memset(m[i], -1, sizeof(int)*(1<<M));
	}

	cout << Dfs(0, 0);
	return 0;
}
