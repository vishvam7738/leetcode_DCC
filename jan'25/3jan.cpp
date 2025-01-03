class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        // for(int i=0;i<n-1;i++){
        //     int l=0,r=0;
        //     for(int j=0;j<=i;j++){
        //         l+=nums[j];
        //     }
        //     for(int j=i+1;j<n;j++){
        //         r+=nums[j];
        //     }
        //     if(l>=r) ans++;
        // }
        // return ans;
        long long sum=0,l=0,r=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        for(int i=0;i<n-1;i++){
            l+=nums[i];
            r=sum-l;
            if(l>=r) ans++;
        }
        return ans;
    }
};
