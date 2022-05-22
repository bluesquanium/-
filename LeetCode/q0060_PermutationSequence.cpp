#define ll long long

class Solution {
public:
    string ans;
    ll kcnt;
    ll check[10];
    ll cnt[10];
    
    void solve(ll cur, ll n, ll k) {
        if(cur == n) {
            kcnt++;
            
            if(kcnt == k) {
                for(ll i = 0; i <n; i++) {
                    ans.push_back(check[i] + '0');
                }   
            }
            return;
        }
        
        for(ll i = 1; i <= n; i++) {
            if(cnt[i] == 0) {
                cnt[i] = 1;
                check[cur] = i;
                solve(cur + 1, n, k);
                cnt[i] = 0;
            }
        }
    }
    
    string getPermutation(int n, int k) {
        kcnt = 0;
        
        solve(0, n, k);
        
        return ans;
    }
};