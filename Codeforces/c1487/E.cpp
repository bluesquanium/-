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

const ll NEWINF = 1000000000000;

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
				n[nSecond][i].first = NEWINF;
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
	cin >> N[1] >> N[2] >> N[3] >> N[4];
	n[1].resize(N[1]);
	n[2].resize(N[2]);
	n[3].resize(N[3]);
	n[4].resize(N[4]);
	for (ll i = 0; i < N[1]; i++) {
		n[1][i].second = i;
		cin >> n[1][i].first;
	}
	for (ll i = 0; i < N[2]; i++) {
		n[2][i].second = i;
		cin >> n[2][i].first;
	}
	for (ll i = 0; i < N[3]; i++) {
		n[3][i].second = i;
		cin >> n[3][i].first;
	}
	for (ll i = 0; i < N[4]; i++) {
		n[4][i].second = i;
		cin >> n[4][i].first;
	}

	cin >> M[1];
	m[1].resize(M[1]);
	for (ll i = 0; i < M[1]; i++) {
		cin >> m[1][i].x >> m[1][i].y;
		m[1][i].x--;
		m[1][i].y--;
	}
	cin >> M[2];
	m[2].resize(M[2]);
	for (ll i = 0; i < M[2]; i++) {
		cin >> m[2][i].x >> m[2][i].y;
		m[2][i].x--;
		m[2][i].y--;
	}
	cin >> M[3];
	m[3].resize(M[3]);
	for (ll i = 0; i < M[3]; i++) {
		cin >> m[3][i].x >> m[3][i].y;
		m[3][i].x--;
		m[3][i].y--;
	}

	cal(1, 2, 1);
	cal(2, 3, 2);
	cal(3, 4, 3);

	sort(n[4].begin(), n[4].end());
	if (n[4][0].first >= NEWINF) {
		cout << "-1";
	}
	else {
		cout << n[4][0].first;
	}

	return 0;
}
