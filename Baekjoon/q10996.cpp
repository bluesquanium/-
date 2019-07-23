#include <iostream>
#include <cstring>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N * 2; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2 == 0) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}cout << '\n';
	}

	return 0;
}
