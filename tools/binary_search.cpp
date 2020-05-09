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

#define BSMAX 100000
bs_arr[BSMAX];
void binarySearch(ll s, ll e, ll target) {
/////////////////////WRONG
	while (s < e) {
		ll mid = (s + e) / 2;
		if (target > m[mid]) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}
}
