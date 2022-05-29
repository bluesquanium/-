class Solution {
public:
    #define ll long long
    
    ll check[10001];
    
    int missingNumber(vector<int>& nums) {
        ll N = nums.size();
        for(ll i = 0; i < N; i++) {
            check[nums[i]] = 1;
        }
        for(ll i = 0; i < 10001; i++) {
            if(check[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};

// class Solution {
// public:
//     #define ll long long
    
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         ll target = 0;
//         for(ll i = 0; i < nums.size(); i++) {
//             if(nums[i] != target) {
//                 return target;
//             }
//             target++;
//         }
        
//         return target;
//     }
// };