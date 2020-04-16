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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, T, ans;
ll m[12];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		m[1] = 1; m[2] = 2; m[3] = 4;
		for (int i = 4; i <= N; i++) {
			m[i] = m[i - 1] + m[i - 2] + m[i - 3];
		}

		cout << m[N] << '\n';
	}

	return 0;
}
