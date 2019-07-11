#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
using namespace std;

vector<int> v;
int N, M;

void solve(int cur, int c) { // cur는 의미없는 인자
	if (c < M) {
		for (int i = 0; i < N; i++) {
			v[c] = i+1;
			solve(i + 1, c + 1);
		}
	}
	else {
		for (int i = 0; i < M; i++) {
			cout << v[i] << ' ';
		}cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	v.resize(M);

	solve(0, 0);

	return 0;
}
