#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define NMAX 14
#define KMAX 14
int N, K, T, ans;
int mem[KMAX + 1][NMAX + 1];

void makeMem() {
	for (int i = 1; i <= NMAX; i++) {
		mem[0][i] = i;
	}
	for (int i = 1; i <= KMAX; i++) {
		int sum = 0;
		for (int j = 1; j <= NMAX; j++) {
			sum += mem[i-1][j];
			mem[i][j] = sum;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	makeMem();

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> K;
		cin >> N;
		cout << mem[K][N] << '\n';
	}

	return 0;
}
