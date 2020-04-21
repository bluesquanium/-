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
vector<pll> m;
map<ll, ll> dict;
vector<ll> bs, dels;
ll mem[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}
	sort(m.begin(), m.end());
	for (int i = 0; i < N; i++) {
		dict[m[i].second] = i;
	}

	mem[0] = -1;
	bs.push_back(m[0].second);
	ans = 1;
	for (int i = 1; i < N; i++) {
		vector<ll>::iterator iter = upper_bound(bs.begin(), bs.end(), m[i].second);
		if (iter == bs.end()) {
			mem[i] = dict[*(iter - 1)];
			bs.push_back(m[i].second);
			ans++;
		}
		else {
			(*iter) = m[i].second;
			if (iter == bs.begin()) {
				mem[i] = -1;
			}
			else {
				mem[i] = dict[*(iter - 1)];
			}
		}
	}

	ll cur = dict[bs.back()];
	while (cur != -1) {
		ll t = cur;
		cur = mem[cur];
		mem[t] = LINF;
	}
	for (int i = 0; i < N; i++) {
		if (mem[i] != LINF) {
			dels.push_back(m[i].first);
		}
	}
	sort(dels.begin(), dels.end());

	cout << N - ans << '\n';
	for (int i = 0; i < dels.size(); i++) {
		cout << dels[i] << '\n';
	}

	return 0;
}
