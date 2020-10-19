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

ll N, M, temp;
vector<pll> ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);

	queue<ll> candi3, candi2; // save height

	ll curHeight = 1;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];

		if (m[i] == 3) {
			if (!candi3.empty()) {
				ll h = candi3.front(); candi3.pop();
				ans.push_back({ h, i + 1 });
				ans.push_back({ curHeight, i + 1 });
				candi3.push(curHeight);

				curHeight++;
			}
			else {
				ans.push_back({ curHeight, i + 1 });
				candi3.push(curHeight);

				curHeight++;
			}
		}
		else if (m[i] == 2) {
			if (!candi3.empty()) {
				ll h = candi3.front(); candi3.pop();
				ans.push_back({ h, i + 1 });
				ans.push_back({ curHeight, i + 1 });
				candi2.push(curHeight);

				curHeight++;
			}
			else {
				ans.push_back({ curHeight, i + 1 });
				candi2.push(curHeight);

				curHeight++;
			}
		}
		else if (m[i] == 1) {
			if (!candi2.empty()) {
				ll h = candi2.front(); candi2.pop();
				ans.push_back({ h, i + 1 });
			}
			else if (!candi3.empty()) {
				ll h = candi3.front(); candi3.pop();
				ans.push_back({ h, i + 1 });
				ans.push_back({ curHeight, i + 1 });

				curHeight++;
			}
			else {
				ans.push_back({ curHeight, i + 1 });

				curHeight++;
			}
		}
	}

	if (candi2.empty() && candi3.empty()) {
		cout << ans.size() << '\n';
		for (ll i = 0; i < ans.size(); i++) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
		}
	}
	else {
		cout << "-1\n";
	}

	return 0;
}
