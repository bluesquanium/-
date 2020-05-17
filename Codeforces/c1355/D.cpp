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

ll N, S, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> S;



	if (N == 1 && S > 1) {
		cout << "YES\n";
		cout << S << '\n';
		cout << 1;
	}
	else if (S / N > 1) {
		cout << "YES\n";
		for (ll i = 0; i < N - 1; i++) {
			cout << 2 << ' ';
		}
		cout << S - 2 * (N - 1) << '\n';
		cout << 1;
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
