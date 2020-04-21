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

ll X, Y, ans;
ll m[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> X >> Y;
	for (int i = 1; i < X; i++) {
		ans += m[i];
	}
	ans += Y - 1;
	
	cout << days[ans % 7];

	return 0;
}
