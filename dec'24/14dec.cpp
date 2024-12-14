class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        long long ans=0;
        map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(abs(mpp.rbegin()->first - mpp.begin()->first)>2){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};
