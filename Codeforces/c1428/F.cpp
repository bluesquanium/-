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

ll N, ans, temp;
string s;
ll lastPos[500001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;
	memset(lastPos, -1, sizeof(ll) * (N + 1));

	ll cnt = 0;
	ll sum = 0;
	// -->
	for (ll i = 0; i < N; i++) {
		if (s[i] == '1') {
			cnt++;
			sum += i - lastPos[cnt];
		}
		else {
			while (cnt) {
				lastPos[cnt] = i - cnt;
				cnt--;
			}
		}
		ans += sum;
	}

	cout << ans;

	return 0;
}
