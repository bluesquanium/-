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

void binarySearch(ll s, ll e) {
	while (s < e) {
		ll mid = (s + e) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (m[i] > mid) {
				sum += m[i] - mid;
			}
		}
		if (sum < M) {
			e = mid;
		}
		else {
			s = mid + 1;
			ans = max(ans, mid);
		}
	}
}
