#define ll long long

class Solution {
public:
    bool isNumber(string s) {
        bool ans = true;
        bool hasE = false;
        ll posE = -1;
        for(ll i = 0; i < s.size(); i++) {
            if(!isValidChar(s[i])) {
                ans = false;
                break;
            } else if (isE(s[i])) {
                if(hasE) {
                    ans = false;
                    break;
                }
                hasE = true;
                posE = i;
            }
        }
        
        if(ans == false) {
            return ans;
        }
        
        if(hasE) {
            string epart = s.substr(posE + 1, s.size());
            s = s.substr(0, posE);
            
            cout << epart.size() << '\n';
            
            if(!isInteger(epart)) {
                ans = false;
            }
            
            cout << s << ' ' << epart << "\n";
        }
        
        ans = ans && (isInteger(s) || isDecimal(s));
        
        return ans;
    }
private:
    bool isDigit(char c) {
        if('0' <= c && c <= '9') {
            return true;
        }
        return false;
    }
    bool isSign(char c) {
        if(c == '+' || c == '-') {
            return true;
        }
        return false;
    }
    bool isDot(char c) {
        if(c == '.') {
            return true;
        }
        return false;
    }
    bool isE(char c) {
        if(c == 'e' || c == 'E') {
            return true;
        }
        return false;
    }
    bool isValidChar(char c) {
        if(isDigit(c) || isSign(c) || isDot(c) || isE(c)) {
            return true;
        }
        return false;
    }
    bool isInteger(string s) {
        if(s.size() == 0) {
            return false;
        }
        if(isSign(s[0])) {
            s = s.substr(1, s.size());
        }
        return isDigits(s);
        
    }
    bool isDigits(string s) {
        if(s.size() == 0) {
            return false;
        }
        for(ll i = 0; i < s.size(); i++) {
            if(!isDigit(s[i])) {
                return false;
            }
        }
        return true;
    }
    bool isDigitsAllowEmpty(string s) {
        if(s.size() == 0) {
            return true;
        }
        for(ll i = 0; i < s.size(); i++) {
            if(!isDigit(s[i])) {
                return false;
            }
        }
        return true;
    }
    bool isDecimal(string s) {
        if(s.size() == 0) {
            return false;
        }
        if(isSign(s[0])) {
            s = s.substr(1, s.size());
        }
        ll hasDot = false;
        ll posDot = -1;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == '.') {
                if(hasDot) {
                    return false;
                }
                hasDot = true;
                posDot = i;
            }
        }
        
        string s1, s2;
        s1 = s.substr(0, posDot);
        s2 = s.substr(posDot + 1, s.size());
        if(s1.size() == 0 && s2.size() == 0) {
            return false;
        }
        
        return isDigitsAllowEmpty(s1) && isDigitsAllowEmpty(s2);
    }
};