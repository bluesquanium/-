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

ll K;
string s;
char dict[11] = "codeforces";
ll num[10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> K;
	for (ll i = 0; i < 10; i++) {
		num[i] = 1;
	}
	ll mul = 1, cur = 0;
	while (mul < K) {
		mul /= num[cur];
		num[cur]++;
		mul *= num[cur];
		cur = (cur + 1) % 10;
	}
	
	for (ll i = 0; i < 10; i++) {
		for (ll j = 0; j < num[i]; j++) {
			cout << dict[i];
		}
	}

	return 0;
}
