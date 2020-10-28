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
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> temp;
		pq.push(temp);
	}

	while (pq.size() != 1) {
		ll num1 = pq.top(); pq.pop();
		ll num2 = pq.top(); pq.pop();
		pq.push(num1 + num2);
		ans += num1 + num2;
	}

	cout << ans;

	return 0;
}
