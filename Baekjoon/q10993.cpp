#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, n, maxY = 3, maxX = 5;
char m[1023][2045];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//Input
	cin >> N; n = N;
	if (N == 1) {
		cout << '*';
		return 0;
	}

	// Finding maxX & maxY
	for (int i = 0; i < N - 2; i++) {
		maxX = maxX + maxY * 2 + 2;
		maxY = maxY * 2 + 1;
	}
	// Init
	for (int i = 0; i < maxY; i++) {
		memset(m[i], ' ', sizeof(char)*(maxX));
	}

	// Algorithm
	int tmaxY = maxY, tmaxX = maxX;
	int mid = maxX / 2, base = 0;
	while (n != 1) {
		if (n % 2 == 0) { // For Even
			for (int i = 0; i < tmaxY; i++) {
				m[base + tmaxY - 1 - i][mid + i] = '*';
				m[base + tmaxY - 1 - i][mid - i] = '*';
			}
			for (int i = 0; i < tmaxX/2; i++) {
				m[base][mid + i] = '*';
				m[base][mid - i] = '*';
			}
		}
		else { // For odd
			for (int i = 0; i < tmaxY; i++) {
				m[base + i][mid + i] = '*';
				m[base + i][mid - i] = '*';
			}
			for (int i = 0; i < tmaxX/2; i++) {
				m[base + tmaxY - 1][mid + i] = '*';
				m[base + tmaxY - 1][mid - i] = '*';
			}
		}

		if (n % 2 == 0) {
			base++;
		}
		else {
			base += tmaxY / 2;
		}
		n--;
		tmaxY = (tmaxY - 1) / 2;
		tmaxX -= tmaxY * 2 + 2;

	}
	m[base][mid] = '*';
	
	//Printing
	for (int i = 0; i < maxY; i++) {
		for (int j = 0; j < maxX; j++) {
			if (N % 2 == 0) { // if N is even,
				if (j > maxX - i-1) {
					break;
				}
			}
			else { //if N is odd,
				if (j > mid+i) {
					break;
				}
			}
			cout << m[i][j];
		}cout << '\n';
	}

	return 0;
}
