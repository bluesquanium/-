#define ll int

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<ll> temp = nums;
        
        // odd even
        ll ptr1 = 0, ptr2 = (nums.size() + 1) / 2;
        ptr1 = ptr2 - 1;
        ptr2 = nums.size() - 1;
        ll i = 0;
        while(i < nums.size()) {
            nums[i++] = temp[ptr1--];
            if(i < nums.size()) {
                nums[i++] = temp[ptr2--];
            }
        }
        
        return;
    }
};