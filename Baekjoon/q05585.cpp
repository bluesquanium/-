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

ll N, M, ans, money = 1000;
ll coins[6] = { 500, 100, 50, 10, 5, 1 };
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	money -= N;
	for (ll i = 0; i < 6; i++) {
		ll num = money / coins[i];
		ans += num;
		money -= num * coins[i];
	}

	cout << ans;

	return 0;
}
