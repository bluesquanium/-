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
ll mem[100];

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
		for (int j = i - 1; j >= 0; j--) {
			if (m[j].second < m[i].second) {
				mem[i] = max(mem[i], mem[j]);
			}
		}
		mem[i]++;
		ans = max(ans, mem[i]);
	}

	cout << N - ans;

	return 0;
}
