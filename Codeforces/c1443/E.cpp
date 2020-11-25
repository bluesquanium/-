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

ll N, Q, ans, temp;
vector<ll> m;
ll mem[200001];
ll f[15];
ll visited[15];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	f[0] = f[1] = 1;
	for (ll i = 2; i <= 14; i++) {
		f[i] = i * f[i - 1];
	}

	cin >> N >> Q;
	for (ll i = 1; i <= N - 14; i++) {
		mem[i] = mem[i - 1] + i;
	}
	vector<ll> candi;
	for (ll i = 0; i < 14 && N - i > 0; i++) {
		candi.push_back(N - i);
	}
	sort(candi.begin(), candi.end());

	ll curPerm = 0;
	for (ll i = 0; i < Q; i++) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			for (ll i = 0; i < 15; i++) {
				visited[i] = 0;
			}
			ll le, ri;
			cin >> le >> ri;
			ll sum = 0;
			if (le < N - 13) {
				sum = mem[min(ri, N - 14)] - mem[le - 1];
			}
			for (ll j = 14; N - j + 1 <= ri; j--) {
				ll cur = N - j + 1;
				if (cur >= 1) {
					ll k = (curPerm / f[j - 1]) % j;
					ll numIdx = 0;
					while (k >= 0) {
						if (visited[numIdx] == 0) {
							if (k == 0) {
								visited[numIdx] = 1;
								break;
							}
							k--;
						}
						numIdx++;
					}

					if (le <= cur && cur <= ri) {
						sum += candi[numIdx];
					}
				}

				
			}

			cout << sum << '\n';
		}
		else {
			ll x;
			cin >> x;
			curPerm += x;
		}
	}

	return 0;
}
