#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define ll	long long
#define pll	pair<ll,ll>
#define ABS(x)	((x) > 0 ? (x) : -(x))
using namespace std;

ll N, ans;
vector<pll> p;
vector<pll> c;
vector<ll> k;
vector<ll> cost;
vector<ll> selected;
vector<ll> generator;
vector<pll> line;

ll distance(pll a, pll b) {
	return ABS(a.first - b.first) + ABS(a.second - b.second);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	p.resize(N); c.resize(N); k.resize(N); cost.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < N; i++) {
		cin >> c[i].first;
		c[i].second = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> k[i];
	}
	sort(c.rbegin(), c.rend());

	while (!c.empty()) {
		pll cur = c.back(); c.pop_back();
		ll min = cur.first, idx = -1;
		for (int i = 0; i < selected.size(); i++) {
			ll cmp = distance(p[cur.second], p[selected[i]]) * (k[cur.second] + k[selected[i]]);
			if ( cmp < min ) {
				min = cmp;
				idx = selected[i];
			}
		}
		ans += min;
		if (idx == -1) {
			generator.push_back(cur.second + 1);
		}
		else {
			line.push_back({ cur.second + 1, idx + 1 });
		}
		selected.push_back(cur.second);
	}

	cout << ans << '\n';
	cout << generator.size() << '\n';
	for (int i = 0; i < generator.size(); i++) {
		cout << generator[i] << ' ';
	}cout << '\n';
	cout << line.size() << '\n';
	for (int i = 0; i < line.size(); i++) {
		cout << line[i].first << ' ' << line[i].second << '\n';
	}

	return 0;
}
