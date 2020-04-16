#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, t;
int cnt[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		cnt[t]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}
