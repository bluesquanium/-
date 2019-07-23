#include <iostream>
#include <cstring>
using namespace std;

int N;
char** m;

void Algorithm(int n, int midY, int midX) {
	if (n < 3) {
		cout << "Error!";
		exit(1);
	}
	else if (n == 3) {
		m[midY-1][midX-1] = '*';
		m[midY-1][midX] = '*';
		m[midY-1][midX+1] = '*';
		m[midY][midX-1] = '*';
		m[midY][midX+1] = '*';
		m[midY+1][midX-1] = '*';
		m[midY+1][midX] = '*';
		m[midY+1][midX+1] = '*';

		return;
	}
	else {
		Algorithm(n / 3, midY - n / 3, midX - n / 3);
		Algorithm(n / 3, midY - n / 3, midX);
		Algorithm(n / 3, midY - n / 3, midX + n / 3);
		Algorithm(n / 3, midY, midX - n / 3);
		Algorithm(n / 3, midY, midX + n / 3);
		Algorithm(n / 3, midY + n / 3, midX - n / 3);
		Algorithm(n / 3, midY + n / 3, midX);
		Algorithm(n / 3, midY + n / 3, midX + n / 3);

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
		m[i] = new char[N];
		memset(m[i], ' ', sizeof(char)*N);
	}

	//Algorithm
	Algorithm(N, N/2, N/2);

	//Printing
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j];
		} cout << '\n';
	}

	for (int i = 0; i < N; i++) {
		delete[] m[i];
	}
	delete[] m;

		return 0;
}
