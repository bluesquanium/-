#include <iostream>
#include <cstring>
using namespace std;

int N;
char** m;

void Algorithm(int maxY, int mid, int base) {
	if (maxY < 3) {
		cout << "Error Occured!";
		exit(1);
	}
	else if (maxY == 3) {
		for (int i = 0; i < maxY; i++) {
			m[base + i][mid + i] = '*';
			m[base + i][mid - i] = '*';
		}
		m[base + 2][mid] = '*';
		m[base + 2][mid + 1] = '*';
		m[base + 2][mid - 1] = '*';
		return;
	}
	else {
		int nextY = maxY / 2;
		Algorithm(nextY, mid, base);
		Algorithm(nextY, mid - nextY, base + nextY);
		Algorithm(nextY, mid + nextY, base + nextY);
		return;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//Input
	cin >> N;
	m = new char*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new char[2 * N - 1];
		memset(m[i], ' ', sizeof(char) * (2 * N - 1));
	}

	//Algorithm
	Algorithm(N, (2 * N - 1) / 2, 0);

	//Printing
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << m[i][j];
		} cout << '\n';
	}

	for (int i = 0; i < N; i++) {
		delete[] m[i];
	}
	delete[] m;

	return 0;
}
