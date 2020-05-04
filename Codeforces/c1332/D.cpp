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

ll K, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> K;

	ll f = 1, num = K;
	while (num) {
		num /= 2;
		f *= 2;
	}

	cout << "3 3\n";
	cout << K + f << ' ' << K + f << ' ' << f << '\n';
	cout << K + f << ' ' << K << ' ' << K + f << '\n';
	cout << f << ' ' << K + f << ' ' << K;

	return 0;
}
