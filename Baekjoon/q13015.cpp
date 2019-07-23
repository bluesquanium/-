#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX	100
using namespace std;

int N;
char m[2*MAX-1][4*MAX-3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++) {
		memset(m[i], ' ', sizeof(char)*(4 * N - 3));
	}

	int i = 0, j = 0;
	for (int c = 0; c < N; c++) {
		m[i][j++] = '*';
	}
	j--;
	for (int c = 0; c < N; c++) {
		m[i++][j++] = '*';
	}
	i--; j--;
	for (int c = 0; c < N; c++) {
		m[i--][j++] = '*';
	}
	i++; j--;
	for (int c = 0; c < N; c++) {
		m[i][j++] = '*';
	}
	j--;
	for (int c = 0; c < N; c++) {
		m[i++][j--] = '*';
	}
	i--; j++;
	for (int c = 0; c < N; c++) {
		m[i++][j++] = '*';
	}
	i--; j--;
	for (int c = 0; c < N; c++) {
		m[i][j--] = '*';
	}
	j++;
	for (int c = 0; c < N; c++) {
		m[i--][j--] = '*';
	}
	i++; j++;
	for (int c = 0; c < N; c++) {
		m[i++][j--] = '*';
	}
	i--; j++;
	for (int c = 0; c < N; c++) {
		m[i][j--] = '*';
	}
	j++;
	for (int c = 0; c < N; c++) {
		m[i--][j++] = '*';
	}
	i++; j--;
	for (int c = 0; c < N; c++) {
		m[i--][j--] = '*';
	}
	
	//m[2N - 1][4N - 3];
	for (int i = 0; i < 2 * N - 1; i++) {
		for (int j = 0; j < 4 * N - 3 - (N-1) + abs(N-1-i); j++) {
			cout << m[i][j];
		}cout << '\n';
	}

	return 0;
}
