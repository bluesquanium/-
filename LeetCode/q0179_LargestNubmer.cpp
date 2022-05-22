#define ll long long

bool cmp(string a, string b) {
    string _a = a, _b = b;
    for(ll i = 0; i < min(a.size(), b.size()); i++) {
        if(a[i] < b[i]) {
            return false;
        } else if (a[i] > b[i]) {
            return true;
        }
    }
    
    while(a.size() != b.size()) {
        if(a.size() < b.size()) {
            a += _a;
        } else {
            b += _b;
        }
    }

    for(ll i = 0; i < a.size(); i++) {
        if(a[i] < b[i]) {
            return false;
        } else if (a[i] > b[i]) {
            return true;
        }
    }
    
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr;
        for(ll i = 0; i < nums.size(); i++) {
            numsStr.push_back(to_string(nums[i]));
        }
        sort(numsStr.begin(), numsStr.end(), cmp);
        
        string ans;
        for(ll i = 0; i < numsStr.size(); i++) {
            ans += numsStr[i];
        }
        
        while(ans.size() > 1) {
            if(ans[0] == '0') {
                ans = ans.substr(1, ans.size());
            } else {
                break;
            }
        }
        
        return ans;
    }
};