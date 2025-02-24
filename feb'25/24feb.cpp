class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> mpp;
    int ans;
    void dfsAlice(int src,int t,int inc,vector<bool>& vis,vector<int>& amt){
        vis[src]=true;
        if(mpp.find(src)==mpp.end()||t<mpp[src]) inc+=amt[src];
        else if(t==mpp[src]) inc+=(amt[src])/2;
        if(adj[src].size()==1&&src!=0) ans=max(ans,inc);
        for(auto& it:adj[src]){
            if(!vis[it]){
                dfsAlice(it,t+1,inc,vis,amt);
            }
        }
    }
    bool dfsBob(int src,vector<bool>& vis,int t){
        vis[src]=true;
        mpp[src]=t;
        if(src==0) return true;
        for(auto& it:adj[src]){
            if(!vis[it]){
                if(dfsBob(it,vis,t+1)==true) return true;
            }
        }
        mpp.erase(src);
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        ans=INT_MIN;
        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int t=0;
        dfsBob(bob,vis,t);
        int inc=0;
        vis.assign(n,false);
        dfsAlice(0,0,inc,vis,amount);
        return ans;
    }
};
