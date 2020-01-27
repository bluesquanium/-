#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define NUMALPHA
int mem[NUMALPHA] = {
	2,2,2,
	3,3,3,
	4,4,4,
	5,5,5,
	6,6,6,
	7,7,7,7,
	8,8,8,
	9,9,9,9,
};

int T, N, ans;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s;
	N = s.size();
	ans += N;
	for (int i = 0; i < N; i++) {
		ans += mem[s[i] - 'A'];
	}

	cout << ans;

	return 0;
}
