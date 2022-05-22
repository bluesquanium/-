#define ll int


class Solution {
public:
    ll check[9];
    vector<vector<string>> ans;

    ll co[9], diag[18], rev_diag[18];

    
    void solve(ll cur, ll n) {
        if(cur == n) {
            vector<string> solution;
            for(ll i = 0; i < n; i++) {
                string s;
                for(ll j = 0; j < n; j++) {
                    if(check[i] == j) {
                        s.push_back('Q');
                    } else {
                        s.push_back('.');
                    }
                }
                solution.push_back(s);
            }
            ans.push_back(solution);
            
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
    
    vector<vector<string>> solveNQueens(int n) {
        for(ll i = 0; i < 9; i++) {
            check[i] = 0;
            co[i] = 0;
        }
        for(ll i = 0; i < 18; i++) {
            diag[i] = rev_diag[i] = 0;
        }
        solve(0, n);
        
        return ans;
    }
};