#define max(A, B) ((A) > (B) ? (A) : (B))
#define ll int

class Solution {
public:    
    ll dict[1000];
    ll wordSizes[1000];
    
    int maxProduct(vector<string>& words) {
        ll ans = 0;
        for(ll i = 0; i < words.size(); i++) {
            dict[i] = 0;
            wordSizes[i] = words[i].size();
            for(ll j = 0; j < wordSizes[i]; j++) {
                dict[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        
        for(ll i = 0; i < words.size(); i++) {
            for(ll j = i + 1; j < words.size(); j++) {
                if((dict[i] & dict[j]) == 0) {
                    ans = max(wordSizes[i] * wordSizes[j], ans);
                }
            }
        }
        
        return ans;
    }
};