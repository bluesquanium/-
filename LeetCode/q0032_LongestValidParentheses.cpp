// '(': 100001, ')': 100002
#define ll int
#define L 100001
#define R 100002

class Solution {
public:
    int longestValidParentheses(string s) {
        ll ans = 0;
        vector<ll> st;
        for(ll i =0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push_back(L);
            } 
            // ')'
            else {
                bool check = 0;
                ll temp = 0;
                while(!st.empty()) {
                    ll cur = st.back(); st.pop_back();
                    if(cur == L) {
                        check= 1;
                        temp += 2;
                        break;
                    } else {
                        temp += cur;
                    }
                }
                
                ans = max(ans, temp);
                if(check) {
                    if(!st.empty() && st.back() != L) {
                        temp += st.back();
                        st.pop_back();
                    }
                    st.push_back(temp);
                    
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};