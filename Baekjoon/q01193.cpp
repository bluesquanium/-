#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll N, q, r;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	
	for (ll i = 1; i < 10000; i++) {
		if (N <= (i * (i + 1)) / 2) {
			q = i;
			r = N - ((i - 1) * i) / 2;
			break;
		}
	}

	if (q % 2) {
		cout << q - r + 1 << '/' << r;
	}
	else {
		cout << r << '/' << q - r + 1;
	}

	return 0;
}
