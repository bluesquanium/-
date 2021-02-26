#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll N, M, ans, temp;
vector<ll> n, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	n.resize(N);  m.resize(M);
	ll nCnt = 0, mCnt = 0;
	for (ll i = 0; i < N; i++) {
		cin >> n[i];
	}
	for (ll i = 0; i < M; i++) {
		cin >> m[i];
	}

	while (nCnt != N || mCnt != M) {
		if (nCnt == N) {
			cout << m[mCnt++] << ' ';
		}
		else if (mCnt == M) {
			cout << n[nCnt++] << ' ';
		}
		else {
			if (n[nCnt] < m[mCnt]) {
				cout << n[nCnt++] << ' ';
			}
			else {
				cout << m[mCnt++] << ' ';
			}
		}
	}

	return 0;
}
