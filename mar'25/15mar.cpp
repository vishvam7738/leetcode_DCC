class Solution {
public:
    int solve(vector<int>& nums,int n, int i,int k,vector<vector<int>>& dp){
        if(k==0) return 0;
        if(i>=n) return INT_MAX;
        if(dp[i][k]!=-1) return dp[i][k];
        int take=max(nums[i],solve(nums,n,i+2,k-1,dp));
        int not_take=solve(nums,n,i+1,k,dp);
        return dp[i][k] = min(take,not_take);
    }
    // void solve(vector<int>& nums,int k,int ind,int& mini,vector<int>& cap){
    //     if(cap.size()==k){
    //         int maxi=0;
    //         for(auto& it:cap){
    //             maxi=max(maxi,it);
    //         }
    //         mini=min(maxi,mini);
    //         return;
    //     }
    //     for(int i=ind;i<nums.size();i++){
    //         // if(!cap.empty()&&i==ind) continue;
    //         cap.push_back(nums[i]);
    //         solve(nums,k,i+2,mini,cap);
    //         cap.pop_back();
    //     }
    // }
    bool isPossible(vector<int>& nums,int mid,int k){
        int house=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                house++;
                i++;
            }
        }
        return house>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        // int mini=INT_MAX;
        // vector<int> cap;
        // solve(nums,k,0,mini,cap);
        // return mini;

        // int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(k+1,-1));
        // return solve(nums,n,0,k,dp);

        int n=nums.size();
        int low=INT_MAX,high=0;
        int ans=high;
        for(int i=0;i<n;i++){
            low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
