class Solution {
public:
    long long findScore(vector<int>& nums) {
        // unordered_map<int,int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        vector<int> vis(n, 0);
        long long ans = 0;
        while (!pq.empty()) {
            int ele = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (!vis[idx]) {
                vis[idx] = 1;
                ans += ele;
                if (idx - 1 >= 0 && !vis[idx - 1])
                    vis[idx - 1] = 1;
                if (idx + 1 < n && !vis[idx + 1])
                    vis[idx + 1] = 1;
            }
        }
        return ans;
    }
};
