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

ll T, N, M, K, maxi, ans;
vector<ll> m;

vector<ll> temp, factors;
bool findFactors(ll num, ll step) {
	bool check = true;

	if (num % K != 0) {
		if (num % K == 1) {
			temp.push_back(step);
		}
		else {
			return false;
		}
	}
	if (num / K > 0) {
		check = findFactors(num / K, step + 1);
	}
	return check;
}

ll square(ll num) {
	ll cnt = 0;
	while(num) {
		num /= K;
		cnt++;
	}
	return cnt + 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 1;
		maxi = 0;
		factors.clear();
		cin >> N >> K;
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> m[i];
			maxi = max(maxi, square(m[i]));
		}

		factors.resize(maxi);
		for (int i = 0; i < N; i++) {
			temp.clear();
			if (findFactors(m[i], 0) == false) {
				ans = 0;
				break;
			}
			for (int i = 0; i < temp.size(); i++) {
				if (factors[temp[i]] != 0) {
					ans = 0;
					break;
				}
				factors[temp[i]] = 1;
			}
		}

		if (ans == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}

	return 0;
}
