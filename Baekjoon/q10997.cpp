#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX	600
using namespace std;
#define DIR	4
int dy[DIR] = {  0, 1, 0,-1 };
int dx[DIR] = { -1, 0, 1, 0 };

int N;
char m[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	if (N == 1) {
		cout << '*';
		return 0;
	}

	for (int i = 0; i < 4 * N - 1; i++) {
		memset(m[i], ' ', sizeof(char)*(4 * N - 3));
	}

	for (int i = 0; i < 4 * N - 1; i++) {
		m[i][0] = '*';
		m[i][4 * N - 4] = '*';
	}
	for (int i = 0; i < 4 * N - 3; i++) {
		m[0][i] = '*';
		m[4 * N - 2][i] = '*';
	}
	m[1][4 * N - 4] = ' ';
	int y = 2, x = 4 * N - 4, dir = 0;
	while (m[y + 2*dy[dir]][x + 2*dx[dir]] != '*' || m[y + 2*dy[(dir + 1)%4]][x + 2*dx[(dir+1)%4]] != '*') {
		if (m[y + 2 * dy[dir]][x + 2 * dx[dir]] != '*') {
			y += dy[dir]; x += dx[dir];
			m[y][x] = '*';
		}
		else {
			dir = (dir + 1) % 4;
			y += dy[dir]; x += dx[dir];
			m[y][x] = '*';
		}
	}
	
	for (int i = 0; i < 4 * N - 1; i++) {
		if (i == 1) {
			cout << "*\n";
			continue;
		}
		for (int j = 0; j < 4*N-3; j++) {
			cout << m[i][j];
		}cout << '\n';
	}

	return 0;
}
