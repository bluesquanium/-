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

struct cmp {
	bool operator() (ll a, ll b) const {
		if (abs(a) == abs(b)) {
			return a < b;
		}
		return abs(a) < abs(b);
	}
};

ll N, M, ans, temp;
multiset<ll, cmp> pq;

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) { // cmd
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << *pq.begin() << '\n';
				pq.erase(pq.begin());
			}
		}
		else { // insert
			pq.insert(temp);
		}
	}

	return 0;
}
