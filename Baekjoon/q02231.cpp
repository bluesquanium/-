#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 1; i <= N; i++) {
		ll num = i, sum = i;
		while(num) {
			sum += num % 10;
			num /= 10;
		}
		
		if(sum == N) {
			ans = i;
			break;
		}
	}
	
	cout << ans;

	return 0;
}
