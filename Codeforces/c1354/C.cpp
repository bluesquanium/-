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

ll A, B, C, D, ans;
vector<ll> m;
ll mem[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> C >> D;
	ll len1 = B - A + 1, len2 = C - B + 1;
	for (ll i = 0; i < min(len1, len2); i++) {
		mem[A + B + i] = mem[A + B + i - 1] + i + 1;
	}
	for (ll i = min(len1, len2); i < max(len1, len2); i++) {
		mem[A + B + i] = mem[A + B + i - 1] + min(len1, len2);
	}
	ll num = min(len1, len2) - 1;
	for (ll i = max(len1, len2); i < len1 + len2 - 1; i++) {
		mem[A + B + i] = mem[A + B + i - 1] + num--;
	}
	for (ll i = A + B + len1 + len2 - 1; i <= 1000000; i++) {
		mem[i] = mem[i - 1];
	}

	
	for (ll c = C; c <= D; c++) {
		ans += mem[1000000] - mem[c];
	}

	cout << ans;

	return 0;
}
