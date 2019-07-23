#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

vector<pii> v; // { n, t }
int N, M, n, t;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "order") {
			cin >> n >> t;
			v.push_back({ t, n });
		}
		else if (s == "sort") {
			sort(v.begin(), v.end());
		}
		else { // complete
			cin >> n;
			vector<pii>::iterator iter;
			for (iter = v.begin(); iter != v.end(); iter++) {
				if ((*iter).second == n) {
					break;
				}
			}
			if (iter == v.end()) {
				cout << "ERR!\n";
				return 0;
			}
			else {
				v.erase(iter);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i].second << ' ';
		}
		if (v.empty()) {
			cout << "sleep";
		}
		cout << '\n';
	}

	return 0;
}
