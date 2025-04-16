class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        long long i=0,j=0,ans=0,n=nums.size();
        unordered_map<int,int>count;
        for(;j<n;j++)
        {
            k-=count[nums[j]]++;
            while(k<=0){
                k+= --count[nums[i++]];
            }
            // k+= --count[nums[i++]];
            ans+=i;
        }
        return ans;
    }
};
