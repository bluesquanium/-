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
vector<ll> a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	a.resize(N); b.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < N; i++) {
		cin >> b[i];
	}
	ll suma = 0, sumb = 0;
	for (ll i = 0; i < N; i++) {
		if (a[i] > b[i]) {
			suma++;
		}
		else if (b[i] > a[i]) {
			sumb++;
		}
	}

	if (suma > 0) {
		cout << sumb / suma + 1;
	}
	else {
		cout << "-1";
	}

	return 0;
}
