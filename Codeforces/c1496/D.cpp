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
vector<ll> m;
vector<pll> lp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	ll isUp;
	if (m[1] == m[0]) {
		isUp = 2;
	}
	else if (m[1] > m[0]) {
		isUp = 1;
	}
	else {
		isUp = 0;
	}
	ll peak = 0, cnt = 1;
	for (ll i = 1; i < N; i++) {
		if (isUp == 2) {
			if (m[i] > m[i - 1]) {
				isUp = 1;
				peak = i - 1;
				cnt = 2;
			}
			else if (m[i] < m[i - 1]) {
				isUp = 0;
				peak = i - 1;
				cnt = 2;
			}
		}
		else if (isUp == 1) {
			if (m[i] > m[i - 1]) {
				cnt++;
			}
			else {
				lp.push_back({ cnt, peak });

				peak = i - 1;
				if (m[i] == m[i - 1]) {
					isUp = 2;
				}
				else {
					isUp = 0;
				}
				cnt = 2;
			}
		}
		else {
			if (m[i] < m[i - 1]) {
				cnt++;
			}
			else {
				lp.push_back({ cnt, peak });

				peak = i - 1;
				if (m[i] == m[i - 1]) {
					isUp = 2;
				}
				else {
					isUp = 1;
				}
				cnt = 2;
			}
		}
	}
	if (isUp != 2) {
		lp.push_back({ cnt, peak });
	}

	sort(lp.begin(), lp.end());
	if (lp.size() == 0) {

	}
	else if (lp.size() == 1) {
	}
	else if (lp.size() == 2) {
		if (lp[1].first != lp[0].first) {
		}
		else {
			//
			ll peakLen = lp[1].first;
			if (m[lp[0].second] < m[lp[0].second + 1]) {
				if (lp[0].second + peakLen - 1 == lp[1].second) {
					if (lp[1].first % 2 == 1) {
						ans = 1;
					}
				}
			}
		}
	}
	else {
		if (lp[lp.size() - 1].first != lp[lp.size() - 3].first) {
			if (lp[lp.size() - 1].first != lp[lp.size() - 2].first) {
			}
			else {
				//
				ll peakLen = lp[lp.size() - 1].first;
				if (m[lp[lp.size() - 2].second] < m[lp[lp.size() - 2].second + 1]) {
					if (lp[lp.size() - 2].second + peakLen - 1 == lp[lp.size() - 1].second) {
						if (lp[lp.size() - 1].first % 2 == 1) {
							ans = 1;
						}
					}
				}
			}
		}
	}
	
	cout << ans;

	return 0;
}
