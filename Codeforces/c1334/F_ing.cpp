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

ll N, M, ans, ansCheck;
vector<pll> m;
vector<ll> B;

void solve(ll cur, ll index, ll cost) {
	if (cur == M + 1) {
		ansCheck = 1;
		for (int i = index; i < N; i++) {
			if (m[i].first > B[cur - 1]) {
				cost += m[i].second;
			}
			else if (m[i].second < 0) {
				cost += m[i].second;
			}
		}
		ans = min(ans, cost);
		return;
	}

	for (int i = index; i < N; i++) {
		if (m[i].first == B[cur]) {
			solve(cur + 1, i + 1, cost);
		}
		else {
			if (m[i].first > B[cur - 1]) {
				cost += m[i].second;
			}
			else if(m[i].second < 0) {
				cost += m[i].second;
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ans = LINF;
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> m[i].second;
	}
	cin >> M;
	B.resize(M + 1);
	B[0] = 0;
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}

	solve(1, 0, 0);

	if (ansCheck) {
		cout << "YES\n" << ans;
	}
	else{
		cout << "NO";
	}

	return 0;
}
