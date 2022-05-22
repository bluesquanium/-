#define ll long long

class Solution {
public:
    class Node {
    public:
        vector<ll> connected;
        string s;
        ll checked;
    };
    Node nodes[5001];
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ll endIdx = -1;
        ll ans = 0;
        wordList.push_back(beginWord);
        reverse(wordList.begin(), wordList.end());
        for(ll i = 0; i< wordList.size(); i++) {
            nodes[i].s = wordList[i];
            nodes[i].checked = 999999;
            
            if(wordList[i] == endWord) {
                endIdx = i;
            }
        }
        
        for(ll i = 0; i < wordList.size(); i++) {
            for(ll j = i + 1; j < wordList.size(); j++) {
                if(i == j) continue;
                
                if(canBeConnected(wordList[i], wordList[j])) {
                    nodes[i].connected.push_back(j);
                    nodes[j].connected.push_back(i);
                }
            }
        }
        
        queue<ll> st;
        st.push(0);
        nodes[0].checked = 1;
        
        while(!st.empty()) {
            ll cur = st.front(); st.pop();
            
            if(cur == endIdx) break;
            
            for(ll i = 0; i < nodes[cur].connected.size(); i++) {
                ll idx = nodes[cur].connected[i];
                if(nodes[idx].checked > nodes[cur].checked + 1) {
                    nodes[idx].checked = nodes[cur].checked + 1;
                    st.push(idx);   
                }
            }
        }
        
        if(endIdx == -1) ans = 0;
        else ans = nodes[endIdx].checked;
        if(ans == 999999) ans = 0;
        
        return ans;
    }
    
    bool canBeConnected(string a, string b) {
        if(a.size() != b.size()) return false;
        
        ll isDiffer = 0;
        for(ll i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                if(isDiffer) {
                    return false;
                }
                isDiffer = 1;
            }
        }
        
        if(isDiffer) {
            return true;   
        }
        return false;
    }
};