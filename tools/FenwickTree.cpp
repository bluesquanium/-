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

#define MAXBIT 300001
class Bit {
public:
	ll tree[MAXBIT];
	
	void init() {
		for(ll i = 0; i < MAXBIT; i++) tree[i] = 0;
	}
	
	void add(ll x, ll v) {
		for(ll i = x; i < MAXBIT; i += i & -i) {
			tree[i] += v;
		}
	}
	
	ll query(ll x) {
		ll ret = 0;
		for(ll i = x; i; i -= i & -i) {
			ret += tree[i];
		}
		return ret;
	}
} bit;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	bit.init();
	bit.add(1, 1);
	bit.add(2, -1);
	bit.add(3, 2);
	bit.add(4, -2);
	cout << bit.query(1) << '\n'; // 1
	cout << bit.query(2) << '\n'; // 0
	cout << bit.query(3) << '\n'; // 2
	cout << bit.query(4) << '\n'; // 0

	return 0;
}
