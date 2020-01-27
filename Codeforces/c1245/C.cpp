#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define ll	long long
#define MOD	1000000007
using namespace std;

ll mem[100001];
ll n, ans = 1;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s;
	n = s.size();

	mem[1] = 1; mem[2] = 2;
	for (int i = 3; i <= n; i++) {
		mem[i] = (mem[i - 1] + mem[i - 2]) % MOD;
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << '0';
			return 0;
		}
		else if (s[i] == 'n' || s[i] == 'u') {
			char target = s[i];
			int cnt = 1;
			for (int j = i + 1; j < n; j++) {
				i = j;
				if (target == s[j]) {
					cnt++;
				}
				else {
					i--;
					break;
				}
			}
			ans = (ans * mem[cnt]) % MOD;
		}
	}

	cout << ans;

	return 0;
}
