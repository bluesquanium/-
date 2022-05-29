class Solution {
public:
    #define ll long long
    #define pll pair<ll,ll>
    #define max(A, B) ((A) > (B) ? (A) : (B))
    
    ll mem[101][101];
    
    int findMaxForm(vector<string>& strs, int CNT0, int CNT1) {
        for(ll i = 0; i < CNT0; i++) {
            for(ll j = 0; j < CNT1; j++) {
                mem[i][j] = 0;
            }
        }
        
        for(ll i = 0; i < strs.size(); i++) {
            vector<pll> hit;
            pll cur = getCnt(strs[i]);
            for(ll j = 0; j <= CNT0; j++) {
                for(ll k = 0; k <= CNT1; k++) {
                    if(mem[j][k] != 0) {
                        ll n0 = j + cur.first, n1 = k + cur.second;
                        if(n0 <= CNT0 && n1 <= CNT1) {
                            hit.push_back({n0 * 1000 + n1, max(mem[n0][n1], mem[j][k] + 1)});
                        }
                    }
                }
            }
            
            for(ll i = 0; i < hit.size(); i++) {
                ll y = hit[i].first / 1000, x = hit[i].first % 1000;
                mem[y][x] = hit[i].second;
            }
            mem[cur.first][cur.second] = max(mem[cur.first][cur.second], 1);
        }
        
        ll ans = 0;
        for(ll i = 0; i <= CNT0; i++) {
            for(ll j = 0; j <= CNT1; j++) {
                ans = max(ans, mem[i][j]);
            }
        }
        
        return ans;
    }
    
    pll getCnt(string s) {
        ll cnt0 = 0, cnt1 = 0;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        return {cnt0, cnt1};
    }
};