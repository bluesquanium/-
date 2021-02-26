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

string N;
ll ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N;
	for (ll i = 0; i < N.size(); i++) {
		ans *= 16;
		if ('0' <= N[i] && N[i] <= '9') {
			ans += N[i] - '0';
		}
		else {
			ans += N[i] - 'A' + 10;
		}
	}

	cout << ans;

	return 0;
}
