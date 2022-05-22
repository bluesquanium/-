#define ll int
class Solution {
public:
    ll check[9];
    ll ans;

    ll co[9], diag[18], rev_diag[18];

    
    void solve(ll cur, ll n) {
        if(cur == n) {
            ans++;
            
            return;
        }
        
        for(ll i = 0; i < n; i++) {
            if(co[i] == 0 && diag[i + cur] == 0 && rev_diag[i + n - cur] == 0) {
                check[cur] = i;
                co[i] = 1;
                diag[i + cur] = 1;
                rev_diag[i + n - cur] = 1;
                solve(cur + 1, n);
                co[i] = 0;
                diag[i + cur] = 0;
                rev_diag[i + n - cur] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        ans = 0;
        
        solve(0, n);
        
        return ans;
    }
};