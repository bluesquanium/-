#include <iostream>
#include <cmath>
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
	
	vector<ll> target;
	for (ll i = 1; i <= N - 1; i += 2) {
		target.push_back(i);
	}

	while (target.size() >= 2) {
		ll num1 = target.back(); target.pop_back();
		ll num2 = target.back(); target.pop_back();

		cout << 2 << ' ' << num1 << ' ' << num2;
		cout << '\n' << flush;

		ll t;
		cin >> t;
		target.push_back(t);
	}

	cout << 0 << '\n' << flush;

	return 0;
}
