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

ll T, D, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> D >> K;

		for (ll i = 1; i <= D; i++) {
			if (i * i * K * K * 2 > D * D) {	
				if (i * i * K * K+ (i - 1) * K * K * (i - 1) > D * D) {
					ans = 1;
				}
				else {
					ans = 0;
				}
				break;
			}
		}

		if (ans) {
			cout << "Utkarsh\n";
		}
		else {
			cout << "Ashish\n";
		}
	}

	return 0;
}
