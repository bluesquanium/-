#include <iostream>
#include <cstring>
using namespace std;

int N;
char ** m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	m = new char*[4 * N - 3];
	for (int i = 0; i < 4 * N - 3; i++) {
		m[i] = new char[4 * N - 3];
		memset(m[i], ' ', sizeof(char)*(4 * N - 3));
	}

	for (int n = 0; n < N; n++) {
		for (int i = n * 2; i < (4*N-3) - n * 2; i++) {
			m[i][n*2] = '*';
			m[i][(4*N-3) - n * 2 - 1] = '*';
			m[n*2][i] = '*';
			m[(4*N-3) - n * 2 - 1][i] = '*';
		}
	}

	for (int i = 0; i < 4 * N - 3; i++) {
		for (int j = 0; j < 4 * N - 3; j++) {
			cout << m[i][j];
		}cout << '\n';
	}

	for (int i = 0; i < 4 * N - 3; i++) {
		delete m[i];
	}
	delete m;

	return 0;
}
