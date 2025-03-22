class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int& v,int& e){
        vis[node]=1;
        v++;
        e+=adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        // vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int v=0,e=0;
                dfs(i,adj,vis,v,e);
                int edge=v*(v-1)/2;
                if(edge==e/2) ans++;
            }
        }
        return ans;
    }
};
