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

ll priority(char s) {
	if (s == '+' || s == '-') {
		return 1;
	}
	else {
		return 2;
	}
}

class Solution {
public:
	int calculate(string s) {
		vector<ll> st;
		vector<ll> st_num;
		ll num = 0;
		for (ll i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				num *= 10;
				num += s[i] - '0';
			}
			else if (s[i] != ' ') {
				st_num.push_back(num);
				num = 0;
				if (st.empty()) {
					st.push_back(s[i]);
				}
				else if (priority(st.back()) < priority(s[i])) {
					st.push_back(s[i]);
				}
				else {
                    while(!st.empty() && priority(st.back()) >= priority(s[i])) {
                        char cmd = st.back();
                        st.pop_back();

                        ll t1 = st_num.back(); st_num.pop_back();
                        ll t2 = st_num.back(); st_num.pop_back();
                        if(cmd == '+') {
                            t2 += t1;
                        }
                        else if(cmd == '-') {
                            t2 -= t1;
                        }
                        else if(cmd == '*') {
                            t2 *= t1;
                        }
                        else {
                            t2 /= t1;
                        }
                        st_num.push_back(t2);
                    }
                    st.push_back(s[i]);
                }
            }
		}
		st_num.push_back(num);

		while (!st.empty()) {
			char cmd = st.back();
			st.pop_back();

			ll t1 = st_num.back(); st_num.pop_back();
			ll t2 = st_num.back(); st_num.pop_back();
            if(cmd == '+') {
                t2 += t1;
            }
            else if(cmd == '-') {
                t2 -= t1;
            }
            else if(cmd == '*') {
                t2 *= t1;
            }
            else {
                t2 /= t1;
            }
            st_num.push_back(t2);
		}

		return st_num.back();
	}
};
