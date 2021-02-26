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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll A, B, C, ans, temp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> C;
	
	if (A > B) {
		swap(A, B);
	}
	if (B > C) {
		swap(B, C);
	}
	if (A > B) {
		swap(A, B);
	}

	cout << A << ' ' << B << ' ' << C;

	return 0;
}
