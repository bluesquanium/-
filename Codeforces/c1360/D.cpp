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

ll T, N, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		
		for(ll i = 1; i * i <= N; i++) {
			if(N % i == 0) {
				if(N / i <= K) {
					ans = i;
					break;
				} else {
					if(i <= K) {
						ans = N / i;
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
