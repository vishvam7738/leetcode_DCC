class Solution {
public:
    long long solve(int i,vector<vector<int>>& questions,int n,vector<long long>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=questions[i][0]+solve(i+questions[i][1]+1,questions,n,dp);
        long long not_take=solve(i+1,questions,n,dp);
        return dp[i]= max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        // vector<long long> dp(n,-1);
        // return solve(0,questions,n,dp);

        vector<long long> dp(200001,0);
        // dp[n]=0;
        long long take=0,not_take=0;
        for(int i=n-1;i>=0;i--){
            take=questions[i][0]+dp[i+questions[i][1]+1];
            not_take=dp[i+1];
            dp[i]=max(take,not_take);
        }
        return dp[0];
    }
};
