class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        int n = gifts.size();
        for (int i = 0; i < n; i++)
            pq.push(gifts[i]);
        while (k > 0) {
            int ele = pq.top();
            pq.pop();
            pq.push((int)(sqrt(ele)));
            k--;
        }
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
