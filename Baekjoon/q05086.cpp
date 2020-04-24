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

ll A, B;
string ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1) {
		ans = "neither\n";
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}

		if (A % B == 0) {
			ans = "multiple\n";
		}
		else if (B % A == 0) {
			ans = "factor\n";
		}

		cout << ans;
	}

	return 0;
}
