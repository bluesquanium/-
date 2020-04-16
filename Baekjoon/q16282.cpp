#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll N, M, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	ll mul = 4;
	for (ll i = 1; i < 1000000; i++) {
		ll num = i + 1;
		num *= mul;
		mul *= 2;
		if (N < num) {
			cout << i;
			break;
		}
	}

	return 0;
}
