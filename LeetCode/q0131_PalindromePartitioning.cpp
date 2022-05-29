class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    vector<string> ps[16];
    vector<pll> check;
    
    vector<vector<string>> ans;
    
    vector<vector<string>> partition(string s) {
        for(ll c1 = 0; c1 < s.size(); c1++) {
            ll r = 0;
            while(0 <= c1 - r && c1 + r < s.size()) {
                if(s[c1 - r] == s[c1 + r]) {
                    ps[c1 - r].push_back(s.substr(c1 - r, r * 2 + 1));
                } else {
                    break;
                }
                r++;
            }
            
            if(c1 + 1 < s.size()) {
                ll c2 = c1 + 1;
                r = 0;
                while(0 <= c1 - r && c2 + r < s.size()) {
                    if(s[c1 - r] == s[c2 + r]) {
                        ps[c1 - r].push_back(s.substr(c1 - r, r * 2 + 2));
                    } else {
                        break;
                    }
                    r++;
                }
            }
        }
        
        solve(0, s.size());
        
        return ans;
    }
    
    vector<string> temp;
    void solve(ll cur, ll N) {
        if(cur == N) {
            temp.clear();
            for(ll i = 0; i < check.size(); i++) {
                temp.push_back(ps[check[i].first][check[i].second]);
            }
            ans.push_back(temp);
            return;
        }
        
        for(ll i = 0; i < ps[cur].size(); i++) {
            check.push_back({cur, i});
            solve(cur + ps[cur][i].size(), N);
            check.pop_back();
        }
    }
};