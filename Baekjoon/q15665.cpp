#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll	long long
using namespace std;

set<int> s;
vector<int> v;
int N, M;

void solve(int cur, int c) {
	if (c < M) {
		auto iter = s.begin();
		for (int i = 0; i < s.size(); i++) { // cur는 의미 없는 인자
			v[c] = *(iter++);
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
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	solve(0, 0);

	return 0;
}
