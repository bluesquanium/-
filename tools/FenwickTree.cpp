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
