#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define NUMALPHA 26
int T, N, ans;
int dict[NUMALPHA];
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	memset(dict, 0, sizeof(int) * NUMALPHA);
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	N = s.size();
	for (int i = 0; i < N; i++) {
		int tar = s[i] - 'A';
		dict[tar]++;
	}

	int maxi = 0, max_idx = -1;
	for (int i = 0; i < NUMALPHA; i++) {
		if (maxi < dict[i]) {
			maxi = dict[i];
			max_idx = i;
		}
		else if (maxi == dict[i]) {
			max_idx = -2;
		}
	}

	if (max_idx == -2) {
		cout << '?';
	}
	else {
		cout << (char)('A' + max_idx);
	}

	return 0;
}
