#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<int> A;
map<int, int> m, ans;
int maxi;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (m.count(A[i]) == 0) {
			m[A[i]] = 1;
		}
		else {
			m[A[i]]++;
		}
	}

	map<int, int> temp;
	int prev = (*m.begin()).first, t_size = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		int cur = (*iter).first;
		if (abs(prev - cur) > 1) {
			if (maxi < t_size) {
				maxi = t_size;
				ans = temp;
			}
			temp.clear();
			temp[(*iter).first] = (*iter).second;
			t_size = (*iter).second;
		}
		else {
			if ((*iter).second == 1) {
				if (temp.size() == 0) {
					temp[(*iter).first] = 1;
					t_size = 1;
				}
				else {
					temp[(*iter).first] = 1;
					t_size += 1;
					if (maxi < t_size) {
						maxi = t_size;
						ans = temp;
					}
					temp.clear();
					temp[(*iter).first] = 1;
					t_size = 1;
				}
			}
			else if ((*iter).second >= 2) {
				temp[(*iter).first] = (*iter).second;
				t_size += (*iter).second;
			}
		}
		prev = cur;
	}
	if (t_size > maxi) {
		maxi = t_size;
		ans = temp;
	}

	cout << maxi << '\n';
	if (ans.size() <= 2) {
		for (auto iter = ans.begin(); iter != ans.end(); iter++) {
			while ((*iter).second != 0) {
				cout << (*iter).first << ' ';
				(*iter).second--;
			}
		}
	}
	else {
		auto iter = ans.begin();
		iter++;
		for (; iter != ans.end(); iter++) {
			cout << (*iter).first << ' ';
			(*iter).second--;
		}

		iter = ans.end();
		iter--;
		for (; iter != ans.begin(); iter--) {
			while ((*iter).second != 0) {
				cout << (*iter).first << ' ';
				(*iter).second--;
			}
		}

		while ((*ans.begin()).second != 0) {
			cout << (*iter).first << ' ';
			(*iter).second--;
		}
	}

	return 0;
}
