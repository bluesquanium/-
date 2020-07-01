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

ll N, M, ans;
ll digit[20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		ll t, cur = 0;
		cin >> t;
		while (t) {
			if (t % 2 == 1) {
				digit[cur]++;
			}
			t /= 2;
			cur++;
		}
	}

	while (1) {
		ll num = 0, curValue = 1;
		for (ll i = 0; i < 20; i++) {
			if (digit[i] != 0) {
				num += curValue;
				digit[i]--;
			}
			curValue *= 2;
		}

		if (num != 0) {
			ans += num * num;
		}
		else {
			break;
		}
	}

	cout << ans;

	return 0;
}
