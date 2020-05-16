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

ll N, M, ans;
string cmd;
ll m[21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> cmd;
		switch (cmd[0]) {
		case 'a':
			if (cmd[1] == 'd') { // 'add'
				cin >> M;
				m[M] = 1;
			}
			else { // 'all'
				for (ll j = 1; j <= 20; j++) {
					m[j] = 1;
				}
			}
			break;
		case 'c': //'check'
			cin >> M;
			if (m[M]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
			break;
		case 'e': //'empty'
			for (ll j = 1; j <= 20; j++) {
				m[j] = 0;
			}
			break;
		case 'r': // 'remove'
			cin >> M;
			m[M] = 0;
			break;
		case 't': // 'toggle'
			cin >> M;
			m[M] = !m[M];
			break;
		}
	}

	return 0;
}
