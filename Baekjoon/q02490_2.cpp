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

ll m, ans;
char dict[5] = { 'D', 'C', 'B', 'A', 'E' };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	for (int i = 0; i < 3; i++) {
		ans = 0;
		for (int j = 0; j < 4; j++) {
			cin >> m;
			ans += m;
		}
		cout << dict[ans] << '\n';
	}

	return 0;
}
