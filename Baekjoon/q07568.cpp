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

ll N, ans;
vector<pll> m;
vector<ll> points;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N); points.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}
	for (int ll i = 0; i < N; i++) {
		for (int ll j = 0; j < N; j++) {
			if (i != j) {
				if (m[i].first < m[j].first && m[i].second < m[j].second) {
					points[i]++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << points[i] + 1 << ' ';
	}

	return 0;
}
