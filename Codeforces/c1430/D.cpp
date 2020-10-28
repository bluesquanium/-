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

ll T, N, M, ans, temp;
string s;

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		cin >> s;
		vector<ll> segs;
		ll curColor = s[0], cnt = 1;
		for (ll i = 1; i < N; i++) {
			if (s[i] == curColor) {
				cnt++;
			}
			else {
				segs.push_back(cnt);
				cnt = 1;
				curColor = s[i];
			}
		}
		if (cnt > 0) {
			segs.push_back(cnt);
		}

		ans = 0;
		ll cur = 0;
		bool noMore = false;
		for (ll i = 0; i < segs.size(); i++) {
			if (noMore == false) {
				while (1) {
					if (cur == segs.size()) {
						noMore = true;
						break;
					}
					if (segs[cur] > 1) {
						segs[cur]--;
						ans++;
						break;
					}
					cur++;
				}
			}
			segs[i] = 0;
			if (noMore) {
				ans++;
				i++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
