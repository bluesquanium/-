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

ll A, B, C, cur, mul, ans;
ll mem[40];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B >> C;
	ans = mul = 1;
	cur = 40 - 1;
	mem[0] = 1; mem[1] = A % C;
	for (int i = 2; i < 40; i++) {
		mem[i] = (mem[i - 1] * mem[i - 1]) % C;
		mul *= 2;
	}
	while (B != 0) {
		if (B - mul >= 0) {
			B -= mul;
			ans = (ans * mem[cur]) % C;
		}
		else {
			mul /= 2;
			cur--;
		}
	}

	cout << ans;

	return 0;
}
