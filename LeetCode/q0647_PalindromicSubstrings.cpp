class Solution {
public:
    int countSubstrings(string s) {
        #define ll int
        ll ans = 0;
        for(ll i = 0; i < s.size(); i++) {
            for(ll j = i; j < s.size(); j++) {
                ans += isPalindrom(s.substr(i, j - i + 1));
            }
        }
        return ans;
    }
    
    bool isPalindrom(string s) {
        ll i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};