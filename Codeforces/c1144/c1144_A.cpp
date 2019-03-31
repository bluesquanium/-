#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
string s;
bool check[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N--) {
		bool ans = true;
		memset(check, 0, sizeof(bool) * 26);
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			int cur = s[i] - 'a';
			if (check[cur] == true) {
				ans = false;
				break;
			}
			else {
				check[cur] = true;
			}
		}

		if (ans == false) {
			cout << "No\n";
		}
		else {
			bool start_t = false;
			for (int i = 0; i < 26; i++) {
				if (check[i] == 1) {
					if (start_t == false) {
						start_t = true;
					}
					else {
						ans = false;;
						break;
					}
					int cur = i;
					while (cur < 26 && check[cur] == true) {
						cur++;
					}
					i = cur - 1;
				}
			}

			if (ans == false) {
				cout << "No\n";
			}
			else {
				cout << "Yes\n";
			}
		}
	}

	return 0;
}
