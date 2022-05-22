#define ll long long 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll times = 1, times_without0 = 1;
        ll cnt0 = 0;
        for(ll i = 0; i < nums.size(); i++) {
            times *= nums[i];
            if(nums[i] != 0) {
                times_without0 *= nums[i];
            } else {
                cnt0++;
            }
        }
        
        for(ll i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(cnt0 == 1) {
                    nums[i] = times_without0;
                } else {
                    nums[i] = times;
                }
            } else {
                nums[i] = times / nums[i];
            }
        }
        
        return nums;
    }
};