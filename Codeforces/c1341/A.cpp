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

ll T, N, M, A, B, C, D, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> A >> B >> C >> D;
		ll mini = (A - B) * N, maxi = (A + B) * N;
		if ( maxi < C - D || C + D < mini) {
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}

	return 0;
}
