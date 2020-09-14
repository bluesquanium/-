#include <iostream>
#include <cmath>
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

ll T, N, ans, temp;
vector<ll> neg, pos;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		neg.clear(); pos.clear();
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> temp;
			if (temp < 0) {
				neg.push_back(temp);
			}
			else {
				pos.push_back(temp);
			}
		}

		if (pos.size() >= 5 || (neg.size() >=2 && pos.size() >= 3) || (neg.size() >= 4 && pos.size() >= 1)) {
			sort(neg.rbegin(), neg.rend());
			sort(pos.begin(), pos.end());
			ans = pos.back(); pos.pop_back();
			ll negNum = -1;
			if (neg.size() >= 2) {
				negNum = neg.back(); neg.pop_back();
				negNum *= neg.back(); neg.pop_back();
			}
			ll posNum = -1;
			if (pos.size() >= 2) {
				posNum = pos.back(); pos.pop_back();
				posNum *= pos.back(); pos.pop_back();
			}
			for (ll i = 0; i < 2; i++) {
				if (negNum < posNum) {
					ans *= posNum;
					posNum = -1;
					if (pos.size() >= 2) {
						posNum = pos.back(); pos.pop_back();
						posNum *= pos.back(); pos.pop_back();
					}
				}
				else {
					ans *= negNum;
					negNum = -1;
					if (neg.size() >= 2) {
						negNum = neg.back(); neg.pop_back();
						negNum *= neg.back(); neg.pop_back();
					}
				}
			}
		}
		else { // absolutely minimum
			sort(neg.begin(), neg.end());
			sort(pos.rbegin(), pos.rend());
			ans = 1;
			for (ll i = 0; i < 5; i++) {
				if (neg.empty()) {
					ans *= pos.back(); pos.pop_back();
				}
				else if (pos.empty()) {
					ans *= neg.back(); neg.pop_back();
				}
				else if (abs(neg.back()) < abs(pos.back())) {
					ans *= neg.back(); neg.pop_back();
				}
				else {
					ans *= pos.back(); pos.pop_back();
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
