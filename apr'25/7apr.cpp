class Solution {
public:
    bool f(int ind, int s, vector<int>& nums, vector<vector<int>>& dp) {
        if (s == 0)
            return true;
        if (ind == 0)
            return (nums[0] == s);
        if (dp[ind][s] != -1)
            return dp[ind][s];
        bool notTake = f(ind - 1, s, nums, dp);
        bool take = false;
        if (s >= nums[ind])
            take = f(ind - 1, s - nums[ind], nums, dp);

        return dp[ind][s] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        if (sum % 2 != 0)
            return false;
        return f(n - 1, sum / 2, nums, dp);
    }
};
