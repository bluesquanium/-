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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, K, ans, temp;
vector<ll> m;
string s;
ll cur[3]; // 0, 1, ?

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		cur[0] = cur[1] = cur[2] = 0;
		cin >> N >> K;
		cin >> s;
		for (ll i = 0; i < K; i++) {
			switch (s[i]) {
			case '0':
				cur[0]++;
				break;
			case '1':
				cur[1]++;
				break;
			case '?':
				cur[2]++;
				break;
			default:
				return -1;
			}
		}
		if (cur[0] > K / 2 || cur[1] > K / 2) {
			ans = 0;
		} else {
			for (ll i = K; i < N; i++) {
				if (s[i] == '0') {
					if (s[i - K] == '1') {
						ans = 0;
						break;
					}

					if (s[i - K] == '?') {
						if (cur[0] + 1 > K / 2) {
							ans = 0;
							break;
						}
						cur[2]--;
						cur[0]++;
					}
				}
				else if (s[i] == '1') {
					if (s[i - K] == '0') {
						ans = 0;
						break;
					}

					if (s[i - K] == '?') {
						if (cur[1] + 1 > K / 2) {
							ans = 0;
							break;
						}
						cur[2]--;
						cur[1]++;
					}
				}
				else {
					if (s[i - K] == '0') {
						s[i] = '0';
					}
					else if (s[i - K] == '1') {
						s[i] = '1';
					}
				}
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
