#include <iostream>
using namespace std;

#define N 10000
int ans;
int mem[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 1; i < N; i++) {
		int num = i, sum = i;
		while (num) {
			sum += (num % 10);
			num /= 10;
		}
		if (sum <= 10000) {
			mem[sum] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (mem[i] == 0) {
			cout << i << '\n';
		}
	}

	return 0;
}
