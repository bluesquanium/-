#define ll long long

class Solution {
public:
    bool isMatch(string s, string p) {
        ll pidx = 0, sidx = 0;
        ll star = -1, ss = sidx;
        while(sidx < s.size()) {
            if(pidx < p.size() && p[pidx] == '?' || p[pidx] == s[sidx]) {
                pidx++;
                sidx++;
            } 
            else if (p[pidx] == '*') {
                star = pidx;
                ss = sidx;
                
                pidx++;
            }
            else if (star != -1) {
                pidx = star + 1;
                sidx = ++ss;
            } else {
                return false;   
            }
        }
        
        while(pidx < p.size() && p[pidx] == '*') {
            pidx++;
        }
        
        return pidx == p.size();
    }
};