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

ll T, N, ans, temp;
char m[50][51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		
		ans = 1;
		for(ll i = 0; i < N-1; i++) {
			for(ll j = 0; j < N-1; j++) {
				if(m[i][j] == '1') {
					if(m[i][j + 1] != '1' && m[i + 1][j] != '1') {
						ans = 0;
					}
				}
			}
		}

		if(ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
