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

ll T, N, K;
string ans;

vector<ll> base[10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 1; i <= 9; i++) {
		ll sum = ((i + 1) * i) / 2;
		for (ll j = 0; j <= 9; j++) {
			base[i].push_back(sum);

			sum -= j;
			
			ll num = i + j + 1;
			while (num) {
				sum = sum + num % 10;
				num /= 10;
			}
		}
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		cin >> N >> K;

		if (K == 0) {
			while (N) {
				if (N > 9) {
					ans += "9";
					N -= 9;
				}
				else {
					string t = ans;
					ans.clear();
					ans.push_back('0' + N);
					ans += t;
					N = 0;
				}
			}
		}
		else {
			bool check = false;
			for (ll i = 0; i < base[K].size(); i++) {
				if (base[K][i] <= N) {
					ll num = N - base[K][i];
					if (num % (K + 1) == 0) {
						ll q = num / (K + 1);
						while (q) {
							if (q > 9) {
								ans += "9";
								q -= 9;
							}
							else {
								string t = ans;
								ans.clear();
								ans.push_back('0' + q);
								ans += t;
								q = 0;
							}
						}

						if (i + K >= 10) {
							string spare;
							spare.push_back('0' + i);

							char last = '0';
							ll j = 1;
							for (; j < 9; j++) {
								if (ans.size() != 0) {
									if (ans[0] - 1 >= '0') {
										ans[0]--;
										last++;
									}
									else {
										break;
									}
								}
							}
							for (; j < 9; j++) {
								if (ans.size() > 1) {
									if (ans[0] == '0' && ans[1] - 1 >= '0') {
										ans[1]--;
										last++;
									}
									else {
										break;
									}
								}
							}
							ans.push_back(last);
							ans += spare;
							if (ans.size() > 1 && ans[0] == '0') {
								ans = ans.substr(1, ans.size() - 1);
							}
						}
						else {
							char last = '0' + i;
							ll j = K;
							for (; j < 9; j++) {
								if (ans.size() != 0) {
									if (ans[0] - 1 >= '0') {
										ans[0]--;
										last++;
									}
									else {
										break;
									}
								}
							}
							for (; j < 9; j++) {
								if (ans.size() > 1) {
									if (ans[0] == '0' && ans[1] - 1 >= '0') {
										ans[1]--;
										last++;
									}
									else {
										break;
									}
								}
							}
							ans.push_back(last);
							if (ans.size() > 1 && ans[0] == '0') {
								ans = ans.substr(1, ans.size() - 1);
							}
						}

						check = true;
						break;
					}
				}
			}
			if (check == false) {
				ans = "-1";
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
