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

ll T, N, L, R, step, cur;
ll m[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> L >> R;
		L--; R--;
		
		cur = 0;
		step = 0;
		for (ll i = N - 1; i >= 0; i--) {
			if (step + (i == 0 ? 1 : i * 2) > L) {
				if (cur < L) cur = L;
				for (; cur < step + (i == 0 ? 1 : i * 2) && cur <= R; cur++) {
					if (cur % 2) {
						cout << N - i + 1 + (cur - step) / 2 << ' ';
					}
					else { // even
						if (i == 0) {
							cout << "1 ";
						}
						else {
							cout << N - i << ' ';
						}
					}
				}
				if (cur > R) {
					break;
				}
			}
			step += i * 2;
		}

		cout << '\n';
	}

	return 0;
}
