class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mode = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                long long adjNode = it.first;
                long long edW = it.second;
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                } else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mode;
                }
            }
        }
        return ways[n - 1] % mode;
    }
};
