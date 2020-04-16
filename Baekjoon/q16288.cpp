#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll N, K, ans;
vector<ll> m;
vector<ll> q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	q.resize(K, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}

	ans = 1;
	for (int i = 0; i < N; i++) {
		int maxIdx = -1, max = -1;
		for (int j = 0; j < K; j++) {
			if (m[i] > q[j] && max < q[j]) {
				max = q[j];
				maxIdx = j;
			}
		}
		if (max == -1 || m[i] < max) {
			ans = 0;
			break;
		}
		q[maxIdx] = m[i];
	}

	if (ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}
