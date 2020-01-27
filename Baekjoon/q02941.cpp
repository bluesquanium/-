#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define NUMKROA 8
int T, N, ans;
string s;
string dict[NUMKROA] = {
	"c=",
	"c-",
	"dz=",
	"d-",
	"lj",
	"nj",
	"s=",
	"z="
};

int checkKroa(int idx) {
	for (int i = 0; i < NUMKROA; i++) {
		if (i == 2) {
			if (idx + 2 < N) {
				if (s[idx] == dict[i][0] && s[idx + 1] == dict[i][1] && s[idx + 2] == dict[i][2]) {
					return 2;
				}
			}
		}
		else {
			if (s[idx] == dict[i][0] && s[idx + 1] == dict[i][1]) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s;
	N = s.size();
	for (int i = 0; i < N; i++) {
		if (checkKroa(i)) {
			i += checkKroa(i);
		}
		ans++;
	}

	cout << ans;

	return 0;
}
