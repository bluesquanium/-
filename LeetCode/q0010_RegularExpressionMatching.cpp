#define ll long long

string s, p;
ll ans = false;

void solve(ll scur, ll pcur) {
    if(pcur == p.size()) {
        if(scur == s.size() && pcur == p.size()) {
            ans = true;
        }
        return;
    }
    
    if(('A' <= p[pcur] && p[pcur] <= 'Z') || (p[pcur] == '.' - 32)) {
        solve(scur, pcur + 1);
        while(scur < s.size() && (s[scur] == p[pcur] + 32 || p[pcur] + 32 == '.')){
            solve(++scur, pcur + 1);
        }
    } else {
        if(scur == s.size()) {
            return;
        }
        
        if(s[scur] != p[pcur] && p[pcur] != '.') {
            return;
        }
        
        solve(scur + 1, pcur + 1);
    }
    
    return;
}

class Solution {
public:
    bool isMatch(string _s, string _p) {
        s = _s; p = _p;
        ans = false;
        string p2;
        for(ll i = 0; i < p.size(); i++) {
            if(p[i] == '*') {
                p2[p2.size() -1] = p2[p2.size() -1] - 32;
            } else {
                p2.push_back(p[i]);
            }
        }
        p = p2;
        
        solve(0, 0);
        
        return ans;
    }
};
