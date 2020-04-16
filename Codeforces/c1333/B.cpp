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

ll T, N, M, ans;
vector<ll> a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = 1;
		a.resize(N); b.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}

		int pPlus = 0, pMinus = 0;
		for (int i = 0; i < N; i++) {
			if (a[i] < b[i]) {
				if (!pPlus) {
					ans = 0;
					break;
				}
			}
			else if (a[i] > b[i]) {
				if (!pMinus) {
					ans = 0;
					break;
				}
			}
			if (a[i] == 1) {
				pPlus = 1;
			}
			else if (a[i] == -1) {
				pMinus = 1;
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
