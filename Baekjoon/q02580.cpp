#include <iostream>
#include <cmath>
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

bool success = false;
ll N, M;
ll m[9][9];
vector<pll> box;
ll visited[10];

void solve(ll cnt) {
	if (cnt == box.size()) {
		success = true;
		return;
	}

	pll cur = box[cnt];
	for (ll i = 1; i <= 9; i++) {
		bool check = true;
		m[cur.first][cur.second] = i;
		for (ll j = 0; j < 10; j++) {
			visited[j] = 0;
		}
		for (ll j = 0; j < 9; j++) {
			if (++visited[m[j][cur.second]] == 2 && m[j][cur.second] != 0) {
				check = false;
				break;
			}
		}
		if (check == false) {
			continue;
		}

		for (ll j = 0; j < 10; j++) {
			visited[j] = 0;
		}
		for (ll j = 0; j < 9; j++) {
			if (++visited[m[cur.first][j]] == 2 && m[cur.first][j] != 0) {
				check = false;
				break;
			}
		}
		if (check == false) {
			continue;
		}

		for (ll j = 0; j < 10; j++) {
			visited[j] = 0;
		}
		for (ll j = (cur.first / 3) * 3; j < (cur.first / 3) * 3 + 3; j++) {
			for (ll k = (cur.second / 3) * 3; k < (cur.second / 3) * 3 + 3; k++) {
				if (++visited[m[j][k]] == 2 && m[j][k] != 0) {
					check = false;
					break;
				}
			}
		}
		if (check == false) {
			continue;
		}
		
		solve(cnt + 1);
		if (success == true) {
			return;
		}
	}
	m[cur.first][cur.second] = 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (ll i = 0; i < 9; i++) {
		for (ll j = 0; j < 9; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) {
				box.push_back({ i, j });
			}
		}
	}

	solve(0);

	for (ll i = 0; i < 9; i++) {
		for (ll j = 0; j < 9; j++) {
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
