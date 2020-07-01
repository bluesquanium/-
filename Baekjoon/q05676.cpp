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

#define MAX 100000

ll N, K, a, b, ans;
char cmd;
vector<ll> m;

ll ft[MAX + 1][3];

int main(void) {
	ios::sync_with_stdio(false);
	
	while (cin >> N >> K) {
		for (ll i = 0; i < N; i++) {
			ft[i][0] = ft[i][1] = ft[i][2] = 0;
		}
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		ll step = 1;
		while (step <= N) {
			for (ll i = 0; i < N; i += step * 2) {
				for (ll j = i; j < i + step && j < N; j++) {
					if (m[j] < 0) {
						ft[i + step][0]++;
					}
					else if (m[j] == 0) {
						ft[i + step][1]++;
					}
					else {
						ft[i + step][2]++;
					}
				}
			}

			step *= 2;
		}

		ll num, mask;
		for (ll i = 0; i < K; i++) {
			cin >> cmd >> a >> b;
			switch (cmd) {
			case 'C':
				a;
				if (m[a-1] < 0) {
					ft[a][0]--;
				}
				else if (m[a-1] == 0) {
					ft[a][1]--;
				}
				else {
					ft[a][2]--;
				}

				if (b < 0) {
					ft[a][0]++;
				}
				else if (b == 0) {
					ft[a][1]++;
				}
				else {
					ft[a][2]++;
				}

				num = a;
				mask = 1;
				for (; mask <= N; mask *= 2) {
					if ((mask & num) != 0) {
						break;
					}
				}
				for (; mask <= N; mask *= 2) {
					if ((mask & num) != 0) {
						num -= (mask & num);
					}
					else {
						if (m[a - 1] < 0) {
							ft[num + mask][0]--;
						}
						else if (m[a - 1] == 0) {
							ft[num + mask][1]--;
						}
						else {
							ft[num + mask][2]--;
						}

						if (b < 0) {
							ft[num + mask][0]++;
						}
						else if (b == 0) {
							ft[num + mask][1]++;
						}
						else {
							ft[num + mask][2]++;
						}
					}
				}

				break;
			case 'P':
				ll cur[3] = { ft[b][0], ft[b][1], ft[b][2] };
				for (ll mask = 1; mask <= N; mask *= 2) {
					if ( (mask & b) != 0) {
						cur[0] += ft[b ^ mask][0];
						cur[1] += ft[b ^ mask][1];
						cur[2] += ft[b ^ mask][2];
					}
				}
				cur[0] -= ft[a - 1][0];
				cur[1] -= ft[a - 1][1];
				cur[2] -= ft[a - 1][2];
				for (ll mask = 1; mask <= N; mask *= 2) {
					if ( (mask & (a - 1)) != 0) {
						cur[0] -= ft[(a - 1) ^ mask][0];
						cur[1] -= ft[(a - 1) ^ mask][1];
						cur[2] -= ft[(a - 1) ^ mask][2];
					}
				}

				if (cur[1] != 0) {
					cout << '0';
				}
				else if (cur[0] % 2 == 0) {
					cout << '+';
				}
				else {
					cout << '-';
				}

				break;
			}
		}

		cout << '\n';
	}

	return 0;
}

