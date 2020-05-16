#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, t, ans;
string cmd;
vector<ll> m;

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	vector<ll> st;
	for (ll i = 0; i < N; i++) {
		cmd.clear();
		cin >> cmd;
		if (cmd == "push") {
			cin >> t;
			st.push_back(t);
		}
		else if (cmd == "pop") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.back() << '\n';
				st.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << st.size() << '\n';
		}
		else if (cmd == "empty") {
			if (st.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else { // "top"
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.back() << '\n';
			}
		}
	}

	return 0;
}
