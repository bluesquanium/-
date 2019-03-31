#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int K;
string s, t;
int* cal, * ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> K;
	cin >> s;
	cin >> t;
	cal = new int[K];
	ans = new int[K];

	for (int i = 0; i < K; i++) {
		ans[i] = s[i];
	}

	for (int i = K - 1; i >= 0; i--) {
		cal[i] = t[i] - s[i];
		if (cal[i] < 0) {
			cal[i] += 26;
			t[i - 1] -= 1;
		}
	}

	for (int i = 0; i < K; i++) {
		if (cal[i] % 2 == 0) {
			cal[i] /= 2;
		}
		else {
			cal[i] /= 2;
			cal[i + 1] += 26;
		}
	}

	for (int i = K - 1; i >= 0; i--) {
		ans[i] += cal[i];
		if (ans[i] > 'z') {
			ans[i] -= 26;
			ans[i - 1] += 1;
		}
	}

	for (int i = 0; i < K; i++) {
		cout << (char)ans[i];
	}

	return 0;
}
