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

class Cmd {
public:
	ll x, y, z;

	Cmd(ll _x, ll _y, ll _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};

ll N, M, ans, temp;
vector<ll> m;
vector<Cmd> cmd;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	ll totalXOR = 0;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		totalXOR = totalXOR ^ m[i];
	}
	
	if (N % 2 == 0 && totalXOR != 0) {
		cout << "NO\n";
	}
	else {
		cmd.push_back(Cmd(1, 2, 3));
		for (ll i = 2; i + 2 < N; i += 2) {
			cmd.push_back(Cmd(i + 1, i + 2, i + 3));
		}
		for (ll i = N - 5 - (N + 1) % 2; i >= 0; i -= 2) {
			cmd.push_back(Cmd(N - (N + 1) % 2, i + 1, i + 2));
		}
		
		cout << "YES\n";
		cout << cmd.size() << '\n';
		for (ll i = 0; i < cmd.size(); i++) {
			cout << cmd[i].x << ' ' << cmd[i].y << ' ' << cmd[i].z << '\n';
		}
	}

	return 0;
}
