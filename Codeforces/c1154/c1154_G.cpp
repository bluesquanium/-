#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define pli	pair<ll,int>
#define ll	long long
#define INF	9223372036854775807
using namespace std;

int N, ans[2];
ll a, mini = INF;
vector<pli> m;

ll Gcd(ll x, ll y) {
	return y == 0 ? x : Gcd(y, x%y);
}

ll Lcm(ll x, ll y) {
	return x * y / Gcd(x, y);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> a;
		m.push_back({ a,i });
	}
	sort(m.begin(), m.end());

	pli cur, prev = { INF, -1 };
	for (int i = 0; i < m.size(); i++) {
		cur = m[i];
		if (cur.first == prev.first) {
			mini = min(mini, cur.first);
			ans[0] = prev.second;
			ans[1] = cur.second;

			while (!m.empty()) {
				if (mini <= m.back().first) {
					m.pop_back();
				}
				else {
					break;
				}
			}
			break;
		}
		prev = cur;
	}

	for(int i = 0; i < m.size(); i++) {
		for (int j = i+1; j < m.size(); j++) {
			ll lcm = Lcm(m[i].first, m[j].first);
			if (mini > lcm) {
				mini = lcm;
				ans[0] = m[i].second;
				ans[1] = m[j].second;

				while (!m.empty()) {
					if (mini <= m.back().first) {
						m.pop_back();
					}
					else {
						break;
					}
				}
			}
		}

	}

	if (ans[0] < ans[1]) {
		cout << ans[0] << ' ' << ans[1];
	}
	else {
		cout << ans[1] << ' ' << ans[0];
	}
	

	return 0;
}
