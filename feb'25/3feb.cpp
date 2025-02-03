class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),inc=1,dec=1;
        int ans=0;
        if(n==1) return 1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]) inc++, dec=1;
            else if(nums[i]>nums[i+1]) dec++, inc=1;
            else inc=dec=1;
            ans=max(ans,max(dec,inc));
        }
        return ans;
    }
};
