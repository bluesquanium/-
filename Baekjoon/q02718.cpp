#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int ** m;

int Solve(int cur, int bm) {
	if (cur == N * 4 && bm == 0) return 1;
	else if (cur < N * 4) {
		int& result = m[cur][bm];
		if (result == -1) {
			if ((bm & 1) == 1) result = Solve(cur + 1, bm >> 1);
			else {
				result = Solve(cur + 1, (bm >> 1) + (1 << 3));
				if (cur % 4 != 3 && (((bm >> 1) & 1) == 0)) result += Solve(cur + 2, (bm >> 2));
			}
		}
		return result;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		m = new int*[N*4];
		for (int i = 0; i < N*4; i++) {
			m[i] = new int[1<<4];
			memset(m[i], -1, sizeof(int) * (1 << 4));
		}

		cout << Solve(0, 0) << '\n';

		for (int i = 0; i < N*4; i++) delete[] m[i];
		delete[] m;
	}
	return 0;
}
