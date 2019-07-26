#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
using namespace std;

ll mini, maxi, ub, ans;
ll m[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> mini >> maxi;
	ub = maxi - mini;
	for (ll i = 2; i*i <= maxi; i++) {
		ll p = i * i;
		ll a = mini % p;
		ll j = a == 0 ? 0 : -a + p;
		for (; j <= ub; j += p) {
			m[j] = 1;
		}
	}

	for (int i = 0; i <= ub; i++) {
		if(m[i] == 1)
			ans++;
	}

	cout << maxi - mini + 1 - ans;

	return 0;
}
