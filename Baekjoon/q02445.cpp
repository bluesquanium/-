#include <iostream>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int j;
		for (j = 0; j < i; j++) {
			cout << '*';
		}
		for (; j < N; j++) {
			cout << ' ';
		}
		for (; j > i; j--) {
			cout << ' ';
		}
		for (; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = N - 1; i > 0; i--) {
		int j;
		for (j = 0; j < i; j++) {
			cout << '*';
		}
		for (; j < N; j++) {
			cout << ' ';
		}
		for (; j > i; j--) {
			cout << ' ';
		}
		for (; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}
