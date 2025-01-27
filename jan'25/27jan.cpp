class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int src,int des,vector<bool>& vis){
        vis[src]=true;
        if(src==des) return true;
        bool flag=false;
        for(auto it: adj[src]){
            if(!vis[it]){
                flag=flag||dfs(adj,it,des,vis);
            }
        }
        return flag;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        } 
        int q=queries.size();
        vector<bool> ans(q);
        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            vector<bool> vis(numCourses,false);
            ans[i]=dfs(adj,u,v,vis);
        }
        return ans;
    }
};
