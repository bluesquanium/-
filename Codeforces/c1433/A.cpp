#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans, temp;
ll mem[10000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll cur, sum = 0, step;
	for (ll digit = 1; digit < 10; digit++) {
		cur = digit;
		step = 1;
		while (cur < 10000) {
			sum += step;
			mem[cur] = sum;

			cur *= 10;
			cur += digit;
			step++;
		}
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		cout << mem[N] << '\n';
	}

	return 0;
}
