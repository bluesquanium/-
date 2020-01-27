#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;

#define PMAX 300000
int prime[PMAX + 1];
int mem[PMAX + 1];

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

void makeMem() {
	int cnt = 0;
	for (int i = 1; i <= PMAX; i++) {
		if (prime[i] == 1) {
			cnt++;
		}
		mem[i] = cnt;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime();
	makeMem();
	cin >> N;
	while (N) {
		cout << mem[N * 2] - mem[N] << '\n';
		cin >> N;
	}
	

	return 0;
}
