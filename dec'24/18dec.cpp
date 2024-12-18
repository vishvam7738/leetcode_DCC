class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int curr = prices[i];
            while (!s.empty() && s.top() > curr) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = curr - s.top();
            } else {
                ans[i] = curr;
            }
            s.push(curr);
        }
        return ans;
    }
};
