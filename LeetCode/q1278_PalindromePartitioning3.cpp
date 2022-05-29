class Solution {
public:
    #define ll long long
    #define min(A, B) ((A) < (B) ? (A) : (B))
    #define INF 999999
    
    ll mem[101][101];
    ll ps[101][101];
    
    int palindromePartition(string s, int k) {
        for(ll i = 0; i < 101; i++) {
            for(ll j = 0; j < 101; j++) {
                mem[i][j] = ps[i][j] = INF;
            }
        }
        for(ll c1 = 0; c1 < s.size(); c1++) {
            ll r = 0;
            ll errCnt = 0;
            while(0 <= c1 - r && c1 + r < s.size()) {
                if(s[c1 - r] != s[c1 + r]) {
                    errCnt++;
                }
                ps[c1 - r][c1 + r] = errCnt;
                
                r++;
            }
            ll c2 = c1 + 1;
            if(c2 < s.size()) {
                r = 0;
                errCnt = 0;
                while(0 <= c1 - r && c2 + r < s.size()) {
                    if(s[c1 - r] != s[c2 + r]) {
                        errCnt++;
                    }
                    ps[c1 - r][c2 + r] = errCnt;
                    
                    r++;
                }
            }
        }
        
        for(ll i = 0; i < s.size(); i++) {
            mem[i + 1][1] = ps[0][i];
        }
        for(ll i = 1; i < s.size(); i++) {
            for(ll j = i; j < s.size(); j++) {
                for(ll k = 1; k < 100; k++) {
                    if(mem[i][k] == INF) continue;
                    ll idx = j + 1;
                    mem[idx][k + 1] = min(mem[idx][k + 1], mem[i][k] + ps[i][j]);
                    
                }
            }
        }
        
        return mem[s.size()][k];
    }
};