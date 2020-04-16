#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, K;
vector<string> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cnt + m[i].size() <= K) {
			cout << m[i] << ' ';
			cnt += m[i].size();
		}
		else {
			cout << '\n' << m[i] << ' ';
			cnt = m[i].size();
		}
	}

	return 0;
}
