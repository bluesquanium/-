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

ll N, M, ans, temp;
vector<ll> m;
typedef struct {
	ll val;
	ll cnt;
	ll startPos;
} Elem;
vector<Elem> st; // ? pluscnt
ll visited[100001];
ll ansArr[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);

	ans = 1;
	ll plusCnt = 0;
	ll totalPlusCnt = 0;
	ll startIdx = 0;
	for (ll i = 0; i < 2 * N; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == '+') {
			plusCnt++;
			totalPlusCnt++;
		}
		else {
			cin >> temp;
			if (ans == 0) {
				continue;
			}
			if (visited[temp] != 0) {
				ans = 0;
				continue;
			}
			if (plusCnt > 0) {
				ansArr[startIdx + plusCnt - 1] = temp;
				if (plusCnt > 1) {
					st.push_back(Elem{ temp + 1, plusCnt - 1, startIdx });
				}
			}
			else {
				if (st.empty() || st.back().val > temp) {
					ans = 0;
					continue;
				}
				ansArr[st.back().startPos + st.back().cnt - 1] = temp;
				st[st.size() - 1].val = temp + 1;
				st[st.size() - 1].cnt--;
				if (st[st.size() - 1].cnt == 0) {
					ll possibleMin = st.back().val;
					st.pop_back();
					if (!st.empty()) {
						st[st.size() - 1].val = max(st[st.size() - 1].val, possibleMin);
					}
				}
			}
			plusCnt = 0;
			startIdx = totalPlusCnt;
		}
	}

	if (ans) {
		cout << "YES\n";
		for (ll i = 0; i < N; i++) {
			cout << ansArr[i] << ' ';
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}
