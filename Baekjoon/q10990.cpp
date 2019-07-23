#include <iostream>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) { // N*2-1
		for (int j = 0; j < N - i; j++) {
			cout << ' ';
		}
		cout << '*';
		for (int j = 0; j < 2*(i - 1)-1; j++) {
			cout << ' ';
		}
		if (i != 1) {
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}
