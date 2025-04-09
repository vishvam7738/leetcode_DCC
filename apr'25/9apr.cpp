class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]<k) return -1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>k){
                ans++;
                while(i+1<n&&nums[i]==nums[i+1]) i++;
            }
        }
        return ans;
    }
};
