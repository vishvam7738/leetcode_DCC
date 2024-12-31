class Solution {
public:
    int solve(int i, int n, vector<int>& days, vector<int>& costs,
              vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        int val = 0;
        for (int ind = 0; ind < 3; ind++) {
            if (ind == 0)
                val = 1;
            if (ind == 1)
                val = 7;
            if (ind == 2)
                val = 30;
            int k = i;
            while (k < n && days[k] < days[i] + val) {
                k++;
            }
            ans = min(ans, costs[ind] + solve(k, n, days, costs, dp));
        }
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, n, days, costs, dp);
    }
};
