#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
using namespace std;

ll N, K, mini, maxi, mul = 1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		mini += i;
	}
	for (int i = 1; i <= K; i++) {
		maxi += mul;
		mul *= 2;
		if (maxi > 1000000000) {
			maxi = 999999999999;
			break;
		}
	}

	if (mini > N || maxi < N) {
		cout << "NO";
	}
	else {
		;
	}

	return 0;
}
