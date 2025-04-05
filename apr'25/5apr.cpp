class Solution {
public:
    void solve(int i,int n,vector<int>& nums,vector<vector<int>>& subs,vector<int>& temp){
        if(i==n){
            subs.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,n,nums,subs,temp);
        temp.pop_back();
        solve(i+1,n,nums,subs,temp);
    }
    int subsetXORSum(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> subs;
        // vector<int> temp;
        // int sum=0;
        // solve(0,n,nums,subs,temp);
        // for(auto& vec:subs){
        //     int xorr=0;
        //     for(auto& it:vec) xorr^=it;
        //     sum+=xorr;
        // }
        // return sum;

        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++) ans|=nums[i];
        return ans<<(n-1);
    }
};
