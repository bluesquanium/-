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
 
ll N, Q, r, c, ans;
ll m[2][100000];
ll mem[100000];
 
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	for (ll t = 0; t < Q; t++) {
		cin >> r >> c;
		r--; c--;
		if (r == 0) {
			if (m[r][c] == 0) {
				ans += mem[c];
			}
			else {
				ans -= mem[c];
			}
			m[r][c] = !m[r][c];
		}
		else {
			if (m[r][c] == 0) {
				if (c - 1 >= 0) {
					mem[c - 1] += 1;
					ans += m[0][c - 1];
				}
				mem[c] += 1;
				ans += m[0][c];
				if (c + 1 < N) {
					mem[c + 1] += 1;
					ans += m[0][c + 1];
				}
			}
			else {
				if (c - 1 >= 0) {
					mem[c - 1] -= 1;
					ans -= m[0][c - 1];
				}
				mem[c] -= 1;
				ans -= m[0][c];
				if (c + 1 < N) {
					mem[c + 1] -= 1;
					ans -= m[0][c + 1];
				}
			}
			
			m[r][c] = !m[r][c];
		}
 
		if (ans > 0) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
		}
	}
 
 
	return 0;
}
