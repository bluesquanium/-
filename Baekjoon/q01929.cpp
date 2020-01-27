#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans;

#define PMAX 1000000
int prime[PMAX + 1];
void findPrime() {
	for (int i = 2; i <= PMAX; i++) {
		if (prime[i] == 0) {
			prime[i] = 1;
			int j = i * 2;
			while (j <= PMAX) {
				prime[j] = -1;
				j += i;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime();
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (prime[i] == 1) {
			cout << i << '\n';
		}
	}

	return 0;
}
