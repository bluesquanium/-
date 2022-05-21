#define ll long long
#define INF 9999999
#define NUM_ALPHA 26
typedef struct Trie {
    ll finish;
    Trie* next[NUM_ALPHA];
    Trie* fail;
    Trie() : finish(INF) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (ll i = 0; i < NUM_ALPHA; i++) {
            if(next[i])
                delete next[i];
        }
    }
    // is duplicated word?
    ll insert(const char* key, ll id) {
        if (*key == '\0') {
            if(finish != INF) {
                return finish;
            }
            finish = id;
            return INF;
        }
        
        ll cur = *key - 'a';
        if (next[cur] == NULL) {
            next[cur] = new Trie();
        }
        return next[cur]->insert(key + 1, id);
    }
    ll find(const char* key) {
        if (*key == '\0') {
            return finish;
        }
        
        ll cur = *key - 'a';
        if (next[cur] != NULL) {
            return next[cur]->find(key + 1);
        }
        
        return INF;
    }
} Trie;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        set<int> _ans;
        vector<int> ans;
        Trie trie;
        ll wTotalCnt = 0;
        ll wcnt[5001];
        for(ll i = 0; i <= words.size(); i++) {
            wcnt[wTotalCnt] = 0;
        }
        for(ll i = 0; i < words.size(); i++) {
            ll isDuplicated = trie.insert(&words[i][0], ++wTotalCnt);
            if(isDuplicated == INF) {
                wcnt[wTotalCnt] = 1;
            } else {
                wcnt[isDuplicated]++;
            }
        }
        
        // cout << "wcnt\n";
        // for(ll i = 0; i < words.size(); i++) {
        //     cout << wcnt[i] << ' ';
        // }
        // cout << '\n';
        
        ll wnum = words.size();
        ll len = words[0].size();
        ll check[5001][2], ccnt = 0, t = 1;
        for(ll start = 0; start < len; start++) {
            vector<ll> symbols;
            for(ll i = start; i < s.size(); i += len) {
                string sub = s.substr(i, len);
                ll cur = trie.find(&sub[0]);
                symbols.push_back(cur);
                //cout << cur << ' ';
            }
            //cout << '\n';
            
            ll base = 0;
            ccnt = 0;
            for(ll i = 0; i <= wnum; i++) {
                check[i][0] = check[i][1] = 0;
            }
            for(ll i = 0; i < symbols.size(); i++) {
                if(symbols[i] == INF) {
                    t++;
                    base = i + 1;
                    ccnt = 0;
                } 
                else {
                    if(check[symbols[i]][0] != t) {
                        check[symbols[i]][0] = t;
                        check[symbols[i]][1] = 1;
                        ccnt++;
                    } else {
                        ccnt++;
                        check[symbols[i]][1]++;
                        
                        while(check[symbols[i]][1] > wcnt[symbols[i]]) {
                            check[symbols[base]][1]--;
                            ccnt--;
                            base++;
                        }
                    }
                    if(ccnt == wnum) {
                        _ans.insert(base * len + start);
                    }
                    // cout << "ccnt: " << ccnt << '\n';
                    // for(ll j = 0; j < wnum; j++) {
                    //     cout << '[' << check[j][0] << ' ' << check[j][1] << ']' << ' ';
                    // }
                    // cout << '\n';
                }
            }
            
        }
        
        for(auto iter = _ans.begin(); iter != _ans.end(); iter++) {
            ans.push_back(*iter);
        }
        
        return ans;
    }
};
