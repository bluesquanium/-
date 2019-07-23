#include <iostream>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for(int i = 0; i< N; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 2*i + 1; j < N*2; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}
