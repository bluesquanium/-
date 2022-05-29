#define max(A, B) ((A) > (B) ? (A) : (B))


class Solution {
public:    
    #define ll long long
    ll dict[1000][26];
    
    int maxProduct(vector<string>& words) {
        ll ans = 0;
        for(ll i = 0; i < words.size(); i++) {
            for(ll j = 0; j < 26; j++) {
                dict[i][j] = 0;
            }
        }
        for(ll i = 0; i < words.size(); i++) {
            for(ll j = 0; j < words[i].size(); j++) {
                dict[i][words[i][j] - 'a'] = 1;
            }
        }
        
        for(ll i = 0; i < words.size(); i++) {
            for(ll j = i + 1; j < words.size(); j++) {
                ll check = 1;
                for(ll k = 0; k < 26; k++) {
                    if(dict[i][k] && dict[j][k]) {
                        check = 0;
                        break;
                    }
                }
                
                if(check) {
                    ans = max(ans, words[i].size() * words[j].size());
                }
            }
        }
        
        return ans;
    }
};