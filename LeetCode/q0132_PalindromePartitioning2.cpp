class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    #define min(A, B) ((A) < (B) ? (A) : (B))
    #define INF 99999999
    vector<ll> ps[2000];
    ll ans;
    
    ll mem[2001];
    
    int minCut(string s) {
        ans = 0;
        for(ll i = 0; i < 2001; i++) {
            mem[i] = INF;
        }
        for(ll c1 = 0; c1 < s.size(); c1++) {
            ll r = 0;
            while(0 <= c1 - r && c1 + r < s.size()) {
                if(s[c1 - r] == s[c1 + r]) {
                    ps[c1 - r].push_back(r * 2 + 1);
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
                        ps[c1 - r].push_back(r * 2 + 2);
                    } else {
                        break;
                    }
                    r++;
                }
            }
        }
        
        for(ll i = 0; i < ps[0].size(); i++) {
            mem[ps[0][i]] = 1;
        }
        for(ll i = 1; i < s.size(); i++) {
            if(mem[i] == INF) {
                continue;
            }
            
            for(ll j = 0; j < ps[i].size(); j++) {
                ll idx = i + ps[i][j];
                mem[idx] = min(mem[idx], mem[i] + 1);
            }
        }
        
        return mem[s.size()] - 1;
    }
};