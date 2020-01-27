#include <iostream>
#define ll	long long
using namespace std;

ll N, P;

ll calnum(ll n) {
	ll cnt = 0;
	while (n != 0) {
		if (n & 1) {
			cnt++;
		}
		n /= 2;
	}
	return cnt;
}

int main(void) {
	cin >> N >> P;

	ll i = 1, cnt ,num = N;
	while ((num -= P) > 0) {
		cnt = calnum(num);
		if (cnt <= i && i <= N) {
			cout << i;
			return 0;
		}
		i++;
	}

	cout << -1;

	return 0;
}
