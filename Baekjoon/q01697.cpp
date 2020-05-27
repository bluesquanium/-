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

#define MAX 100000

ll N, K, ans;
ll mem[MAX + 1];
vector<ll> st, st2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	N; K;
	st.push_back(N);
	mem[N] = 1;
	while (!st.empty()) {
		while (!st.empty()) {
			ll cur = st.back(); st.pop_back();
			if (cur == K) {
				cout << ans;
				return 0;
			}
			if (0 <= cur - 1 && mem[cur - 1] == 0) {
				mem[cur - 1] = 1;
				st2.push_back(cur - 1);
			}
			if (cur + 1 <= MAX && mem[cur + 1] == 0) {
				mem[cur + 1] = 1;
				st2.push_back(cur + 1);
			}
			if (cur * 2 <= MAX && mem[cur * 2] == 0) {
				mem[cur * 2] = 1;
				st2.push_back(cur * 2);
			}
		}
		st = st2;
		st2.clear();

		ans++;
	}

	return 0;
}
