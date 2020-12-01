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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll N, K, ans, temp;
vector<ll> m;
priority_queue< ll, vector<ll>, less<ll> > pq;
vector<ll> candi;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.rbegin(), m.rend());
	ll point = 0;

	for (ll i = 0; i < N; i++) {
		ans += point;
		point += m[i];
		if (point < 0) {
			point -= m[i];
			for (ll j = i; j < N - K - 1; j++) {
				candi.push_back(m[j]);
			}
			pq.push(point);
			for (ll i = 0; i < K; i++) {
				pq.push(0);
			}
			break;
		}
	}

	for (ll i = 0; i < candi.size(); i++) {
		ll cur = pq.top(); pq.pop();
		pq.push(cur + candi[i]);
		ans += cur + candi[i];
	}

	cout << ans;

	return 0;
}
