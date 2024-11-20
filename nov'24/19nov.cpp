class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> mpp;
        long long ans=0,sum=0;
        while(j<n){
            mpp[nums[j]]++;
            sum+=nums[j];
            if((j-i+1)<k) j++;
            else{
                if(mpp.size()==k) ans=max(ans,sum);
                sum-=nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
