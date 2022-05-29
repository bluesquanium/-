#define max(A, B) ((A) > (B) ? (A) : (B))
#define ll int
#define MASK 0xff
ll cnt[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2,
    3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3,
    3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1,    
    2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
    3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 
    5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2,
    2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 
    4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 
    3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 
    4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5,
    5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4,
    5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 
    2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4,
    5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
    4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3,
    4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5,
    6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4,
    4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 
    4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6,
    5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 
    6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5,
    5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6,
    7, 7, 8
};

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
                dict[i] = dict[i] | (1 << (words[i][j] - 'a'));
            }
        }
        
        for(ll i = 0; i < words.size(); i++) {
            for(ll j = i + 1; j < words.size(); j++) {
                ll check = 1;
                if(wordSizes[i] * wordSizes[j] > ans) {
                    for(ll k = 0; k < 4; k++) {
                        ll curi = (dict[i] >> (8 * k)) & MASK;
                        ll curj = (dict[j] >> (8 * k)) & MASK;
                        if(cnt[curi] + cnt[curj] != cnt[curi | curj]) {
                            check = 0;
                            break;
                        }
                    }
                    if(check) {
                        ans = max(wordSizes[i] * wordSizes[j], ans);
                    }
                }
            }
        }
        
        return ans;
    }
};