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

class Solution {
public:
	int calculate(string s) {
		vector<ll> st;
		vector<ll> st_num;
		ll num = 0, num_check = 0;
		for (ll i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				num_check = 1;
				num *= 10;
				num += s[i] - '0';
			}
			else if (s[i] != ' ') {
				if (s[i] == '(') {
					st.push_back(s[i]);
				}
				else if (s[i] == ')') {
					if (num_check) {
						st_num.push_back(num);
						num = 0;
						num_check = 0;
					}
					
					while (!st.empty()) {
						char cmd = st.back();
						st.pop_back();
						if (cmd == '(') {
							break;
						}

						ll t1 = st_num.back(); st_num.pop_back();
						ll t2 = st_num.back(); st_num.pop_back();
						if (cmd == '+') {
							t2 += t1;
						}
						else {
							t2 -= t1;
						}
						st_num.push_back(t2);
					}
				}
				else {
					if (num_check) {
						st_num.push_back(num);
						num = 0;
						num_check = 0;
					}

					if (!st.empty() && st.back() != '(') {
						char cmd = st.back();
						st.pop_back();

						ll t1 = st_num.back(); st_num.pop_back();
						ll t2 = st_num.back(); st_num.pop_back();
						if (cmd == '+') {
							t2 += t1;
						}
						else {
							t2 -= t1;
						}
						st_num.push_back(t2);
					}
					st.push_back(s[i]);
				}
			}
		}
		if (num_check == 1) {
			st_num.push_back(num);
		}

		while (!st.empty()) {
			char cmd = st.back();
			st.pop_back();

			ll t1 = st_num.back(); st_num.pop_back();
			ll t2 = st_num.back(); st_num.pop_back();
			if (cmd == '+') {
				t2 += t1;
			}
			else {
				t2 -= t1;
			}
			st_num.push_back(t2);
		}

		return st_num.back();
	}
};
