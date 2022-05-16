#define ll long long

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(ll i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        
        double ans = nums1[nums1.size() / 2];
        if(nums1.size() % 2 == 0) {
            ans += nums1[nums1.size() / 2 - 1];
            ans /= 2;
        }
        
        return ans;
    }
};