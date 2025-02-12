class Solution {
public:
    int solve(int n1){
        int s1=0,s2=0;
        while(n1>0){
            s1+=n1%10;
            n1/=10;
        }
        // while(n2>0){
        //     s2+=n2%10;
        //     n2/=10;
        // }
        return s1;
    }
    int maximumSum(vector<int>& nums) {
        // int n=nums.size();
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i+1;j<n;j++){
        //         int n1=nums[i],n2=nums[j];
        //         if(solve(n1,n2)){
        //             sum=n1+n2;
        //             ans=max(sum,ans);
        //         }
        //     }
        // }
        // return ans==INT_MIN?-1:ans;

        unordered_map<int,int> mpp;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=solve(nums[i]);
            if(mpp.count(sum)) ans=max(ans,nums[i]+mpp[sum]);
            mpp[sum]=max(mpp[sum],nums[i]);
        }
        return ans==INT_MIN?-1:ans;
    }
};
