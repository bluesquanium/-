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

ll N, M, temp;
ll m[100001][2];
ll sole[100001];
ll checked[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (ll i = 1; i <= N; i++) {
		ll k;
		cin >> k;
		for (ll j = 0; j < k; j++) {
			cin >> temp;
			m[i][j] = temp;
		}
		if (k == 1 && sole[m[i][0]] == 0) {
			sole[m[i][0]] = i;
		}
	}

	set<ll> ans;
	/*for (ll i = 1; i <= N; i++) {
		if (sole[i] == 1) {
			ans.insert(i);
		}
	}*/
	for (ll i = 1; i <= N; i++) {
		if (m[i][1] != 0) {
			if (sole[m[i][0]] != 0 && sole[m[i][1]] == 0) {
				if (checked[m[i][0]] == 0 || checked[m[i][1]] == 0) {
					ans.insert(i);
					ans.insert(sole[m[i][0]]);
					checked[m[i][0]] = 1;
					checked[m[i][1]] = 1;
				}
			} 
			else if (sole[m[i][1]] != 0 && sole[m[i][0]] == 0) {
				if (checked[m[i][0]] == 0 || checked[m[i][1]] == 0) {
					ans.insert(i);
					ans.insert(sole[m[i][1]]);
					checked[m[i][0]] = 1;
					checked[m[i][1]] = 1;
				}
			}
		}
		else {
			if (checked[m[i][0]] == 0) {
				ans.insert(i);
			}
		}
	}

	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << (*iter) << ' ';
	}

	return 0;
}
