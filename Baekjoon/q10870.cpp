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
vector<ll> m;

ll Fibonacci(ll n) {
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	
	cout << Fibonacci(N);

	return 0;
}
