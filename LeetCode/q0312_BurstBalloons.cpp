#define ll long long

class Solution {
    ll mem[302][302];
    
public:
    int maxCoins(vector<int>& nums) {
        ll N = nums.size();
        for(ll i = 0; i < 302; i++) {
            for(ll j = 0; j < 302; j++) {
                mem[i][j] = 0;
            }
        }
        
        vector<int> temp;
        temp.push_back(1);
        for(ll i = 0; i < N; i++) {
            temp.push_back(nums[i]);
        }
        temp.push_back(1);
        nums = temp;
        
        for(ll blockSize = 1; blockSize <= N; blockSize++) {
            for(ll left = 1; left <= N; left++) {
                ll right = left + blockSize - 1;
                
                if(right > N) continue;
                
                for(ll last = left; last <= right; last++) {
                    ll sum = 0;
                    // lPart
                    if(left <= last - 1) {
                        sum += mem[left][last - 1];
                    }
                    // rPart
                    if(last + 1 <= right) {
                        sum += mem[last + 1][right];
                    }
                    // lastPart
                    sum += nums[left - 1] * nums[last] * nums[right + 1];
                    mem[left][right] = max(mem[left][right], sum);
                }
            }
        }
        
        // for(ll i = 1; i <= N; i++) {
        //     for(ll j = 1; j <= N; j++) {
        //         cout << mem[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        
        return mem[1][N];
    }
};