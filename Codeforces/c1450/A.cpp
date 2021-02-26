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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll T, N, ans, temp;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		cin >> s;

		queue<ll> qindexes;
		for (ll i = 0; i < N; i++) {
			if (s[i] == 't') {
				qindexes.push(i);
			}
			else if (s[i] == 'b') {
				if (qindexes.size() != 0) {
					swap(s[i], s[qindexes.front()]);
					qindexes.pop();
					qindexes.push(i);
				}
			}
		}

		cout << s << '\n';
	}

	return 0;
}
