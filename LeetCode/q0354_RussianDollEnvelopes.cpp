#define ll int

ll ans[100000], aCnt;

class Solution {
public:
    static bool cmp(vector<ll> &a, vector<ll> &b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }

    
    int maxEnvelopes(vector<vector<ll>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        aCnt = 0;
        ans[0] = envelopes[0][1];
        aCnt++;
        ll N = envelopes.size();
        for(ll i = 1; i < N; i++) {
            ll cur = envelopes[i][1];
            if(ans[aCnt - 1] < cur) {
                ans[aCnt++] = cur;
            } else {
                *lower_bound(ans, ans + aCnt, cur) = cur;
            }
        }
        
        return aCnt;
    }
};

