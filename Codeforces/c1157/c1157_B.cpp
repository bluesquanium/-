#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
string s;
int f[10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;
	for (int i = 1; i <= 9; i++) {
		cin >> f[i];
	}

	bool contig = false;
	bool contig2 = true;
	for (int i = 0; i < N; i++) {
		if (contig) {
			contig2 = false;
		}

		if (contig || contig2) {
			if ((s[i] - '0') < f[s[i] - '0']) {
				s[i] = '0' + f[s[i] - '0'];
				contig = true;
			}
			else if ((s[i] - '0') == f[s[i] - '0']) {
				;
			}
			else {
				contig = false;
			}
		}
	}

	cout << s;

	return 0;
}
