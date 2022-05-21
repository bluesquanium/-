#define ll int

class Solution {
public:
    int trap(vector<int>& height) {
        ll ans = 0;
        ll pidx = 0;
        for(ll i = 0; i < height.size(); i++) {
            if(height[i] > height[pidx]) {
                pidx = i;
            }
        }
        
        // ->
        ll bidx = 0; // base idx
        for(ll i = 1; i < pidx; i++) {
            if(height[bidx] < height[i]) {
                for(ll j = bidx + 1; j < i; j++) {
                    ans += height[bidx] - height[j];
                }
                
                bidx = i;
            }
        }
        
        for(ll i = bidx + 1; i < pidx; i++) {
            ans += height[bidx] - height[i];
        }
        
        // <-
        bidx = height.size() - 1;
        for(ll i = height.size() - 2; i > pidx; i--) {
            if(height[bidx] < height[i]) {
                for(ll j = bidx - 1; j > i; j--) {
                    ans += height[bidx] - height[j];
                }
                
                bidx = i;
            }
        }
        
        for(ll i = bidx - 1; i > pidx; i--) {
            ans += height[bidx] - height[i];
        }
        
        return ans;
    }
};