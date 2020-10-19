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

ll N, M, temp;
string s;

typedef struct {
	char type;
	ll i;
} Cmd;
vector<Cmd> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s;
	N = s.size();

	Cmd t;
	t.type = 'L'; t.i = 2;
	ans.push_back(t);
	N++;
	t.type = 'R'; t.i = N - 1;
	ans.push_back(t);
	N++;
	t.type = 'R'; t.i = 2;
	ans.push_back(t);
	N += N - 2;
	t.type = 'R'; t.i = N - 1;
	ans.push_back(t);
	N++;

	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i].type << ' ' << ans[i].i << '\n';
	}

	return 0;
}
