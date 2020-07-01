#include <iostream>
#include <cmath>
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

ll N, ans;
string s;
double num[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;
	for (ll i = 0; i < N; i++) {
		cin >> num[i];
	}

	vector<double> st;
	for (ll i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			st.push_back(num[s[i] - 'A']);
		}
		else {
			double n2 = st.back(); st.pop_back();
			double n1 = st.back(); st.pop_back();

			switch (s[i]) {
			case '+':
				st.push_back(n1 + n2);
				break;
			case '-':
				st.push_back(n1 - n2);
				break;
			case '*':
				st.push_back(n1 * n2);
				break;
			case '/':
				st.push_back(n1 / n2);
				break;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.back();

	return 0;
}
