#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int T, N, A, B, C, ans;
string s, s2;
vector<int> idx;
int bob[3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {
		idx.clear();
		bob[0] = bob[1] = bob[2] = ans = 0;
		cin >> N;
		cin >> A >> B >> C;
		cin >> s;
		s2.resize(N);
		for (int i = 0; i < N; i++) {
			if (s[i] == 'R') {
				bob[0]++;
			}
			else if (s[i] == 'P') {
				bob[1]++;
			}
			else {
				bob[2]++;
			}
		}
		ans = min(A, bob[2]) + min(B, bob[0]) + min(C, bob[1]);
		
		if (ans >= (N + 1) / 2) {
			cout << "YES\n";
			for (int i = 0; i < N; i++) {
				if (s[i] == 'R') {
					if (B > 0) {
						B--;
						s2[i] = 'P';
					}
					else {
						idx.push_back(i);
					}
				}
				else if (s[i] == 'P') {
					if (C > 0) {
						C--;
						s2[i] = 'S';
					}
					else {
						idx.push_back(i);
					}
				}
				else {
					if (A > 0) {
						A--;
						s2[i] = 'R';
					}
					else {
						idx.push_back(i);
					}
				}
			}
			for (int i = 0; i < idx.size(); i++) {
				if (A > 0) {
					A--;
					s2[idx[i]] = 'R';
				}
				else if (B > 0) {
					B--;
					s2[idx[i]] = 'P';
				}
				else if (C > 0) {
					C--;
					s2[idx[i]] = 'S';
				}
				else {
					cout << "ERR!\n";
					return -1;
				}
			}
			cout << s2 << '\n';
		}
		else {
			cout << "NO\n";
		}
	}


	return 0;
}
