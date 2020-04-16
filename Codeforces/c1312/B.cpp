#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
using namespace std;

int T, N, M, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		sort(m.rbegin(), m.rend());
		for (int i = 0; i < N; i++) {
			cout << m[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
