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

ll N, M, ans;
ll num;
string cmd;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> ans;
	cin >> cmd;

	while (1) {
		cin >> num;
		if (cmd == "+") {
			ans += num;
		}
		else if (cmd == "-") {
			ans -= num;
		}
		else if (cmd == "*") {
			ans *= num;
		}
		else {
			ans /= num;
		}
		cin >> cmd;

		if (cmd == "=") {
			break;
		}
	}

	cout << ans;

	return 0;
}
