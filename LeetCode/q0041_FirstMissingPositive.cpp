#define ll int

class Solution {
public:
    ll check[500001];
    
    int firstMissingPositive(vector<int>& nums) {
        ll ans = 500001;
        
        for(ll i = 0; i < nums.size(); i++) {
            if(1 <= nums[i] && nums[i] < 500001) {
                check[nums[i]] = 1;
            }
        }
        
        for(ll i = 1; i < 500001; i++) {
            if(check[i] == 0) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};