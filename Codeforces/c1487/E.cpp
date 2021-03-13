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

class mType {
public:
	ll value;
	ll x;
	ll y;
};

bool cmpM(mType a, mType b) {
	return a.value < b.value;
}

ll N[5], M[4];
vector<pll> n[5];
vector<mType> m[4];

ll originIdxToCurIdx[150000];

void cal(ll nFirst, ll nSecond, ll mIdx) {
	sort(n[nFirst].begin(), n[nFirst].end());
	for (ll i = 0; i < N[nFirst]; i++) {
		originIdxToCurIdx[n[nFirst][i].second] = i;
	}
	for (ll i = 0; i < M[mIdx]; i++) {
		m[mIdx][i].value = m[mIdx][i].y * N[nFirst] + originIdxToCurIdx[m[mIdx][i].x];
	}
	sort(m[mIdx].begin(), m[mIdx].end(), cmpM);

	ll mCur = 0;
	for (ll i = 0; i < N[nSecond]; i++) {
		if (mCur < M[mIdx] && m[mIdx][mCur].y == n[nSecond][i].second) {
			ll cur = 0;
			while (mCur < M[mIdx] && m[mIdx][mCur].y == n[nSecond][i].second && m[mIdx][mCur].x == n[nFirst][cur].second) {
				cur++;
				mCur++;
			}
			if (cur < N[nFirst]) {
				n[nSecond][i].first += n[nFirst][cur].first;
			}
			else {
				n[nSecond][i].first = INF;
			}
		}
		else {
			n[nSecond][i].first += n[nFirst][0].first;
		}

		while (mCur < M[mIdx] && m[mIdx][mCur].y == n[nSecond][i].second) {
			mCur++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (ll i = 1; i <= 4; i++) {
		cin >> N[i];
		n[i].resize(N[i]);
	}
	for (ll i = 1; i <= 4; i++) {
		for (ll j = 0; j < N[i]; j++) {
			n[i][j].second = j;
			cin >> n[i][j].first;
		}
	}

	for (ll i = 1; i <= 3; i++) {
		cin >> M[i];
		m[i].resize(M[i]);
		for (ll j = 0; j < M[i]; j++) {
			cin >> m[i][j].x >> m[i][j].y;
			m[i][j].x--;
			m[i][j].y--;
		}
	}

	cal(1, 2, 1);
	cal(2, 3, 2);
	cal(3, 4, 3);

	sort(n[4].begin(), n[4].end());
	if (n[4][0].first >= INF) {
		cout << "-1";
	}
	else {
		cout << n[4][0].first;
	}

	return 0;
}
