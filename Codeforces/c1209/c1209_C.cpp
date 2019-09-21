#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int T, N;
string s, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {
		ans.clear();
		s.clear();
		cin >> N >> s;
		ans.resize(N);

		int max1, max2 = s[0], check = 0, min2;
		for (int i = 1; i < s.size(); i++) {
			if (check == 0 && s[i] < max2) {
				check = 1;

				max1 = s[i];
				ans[i] = '1';
				for (int j = 0; j < i; j++) {
					if (s[i] < s[j]) {
						min2 = s[j];
						string t; t.resize(i - j, '2');
						ans.replace(j, i - j, t);
						break;
					}
					else {
						ans[j] = '1';
					}
				}
			}
			else if (check == 0) {
				max2 = s[i];
			}
			else {
				if (s[i] >= max2) {
					max2 = s[i];
					ans[i] = '2';
				}
				else if (min2 >= s[i] && s[i] >= max1) {
					max1 = s[i];
					ans[i] = '1';
				}
				else {
					check = -1;
					break;
				}
			}
		}

		if (check == -1) {
			cout << "-\n";
		}
		else if (check == 0) {
			ans.clear();
			ans.resize(N, '2');
			cout << ans << '\n';
		}
		else { // check == 1
			cout << ans << '\n';
		}
	}

	return 0;
}
