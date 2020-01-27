#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans, mini;
int prime[10001];

void findPrime() {
	for (int i = 2; i < 10001; i++) {
		if (prime[i] == 0) {
			prime[i] = 1;
			int j = i * 2;
			while (j < 10001) {
				prime[j] = -1;
				j += i;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> M;
	cin >> N;

	findPrime();

	for (int i = M; i <= N; i++) {
		if (prime[i] == 1) {
			ans += i;
			if (mini == 0) {
				mini = i;
			}
		}
	}

	if (ans) {
		cout << ans << '\n' << mini;
	}
	else {
		cout << -1;
	}

	return 0;
}
