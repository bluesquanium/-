#define ll long long
#define max(A, B) ((A) > (B) ? (A) : (B))

class Solution {
public:
    ll mem[2500];
    
    int lengthOfLIS(vector<int>& nums) {
        ll ans = 1;
        for(ll i = 0; i < nums.size(); i++) {
            mem[i] = 1;
            for(ll j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    mem[i] = max(mem[i], mem[j] + 1);
                    if(mem[i] > ans) {
                        ans = mem[i];
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};