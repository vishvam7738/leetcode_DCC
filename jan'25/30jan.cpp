class Solution {
public:
    int getMaxi(unordered_map<int,vector<int>>& adj,int i,vector<bool>& vis,vector<int>& lev){
        int maxi=lev[i];
        vis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it]){
                maxi=max(maxi,getMaxi(adj,it,vis,lev));
            }
        }
        return maxi;
    } 

    int bfs(unordered_map<int,vector<int>>& adj,int i,int n){
        queue<int> q;
        vector<bool> vis(n+1,false);
        q.push(i);
        vis[i]=true;
        int lev=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int node=q.front();
                q.pop();;
                for(auto it:adj[node]){
                    if(vis[it]) continue;
                    q.push(it);
                    vis[it]=true;
                }
            }
            lev++;
        }
        return lev;
    }

    bool isBipartite(unordered_map<int,vector<int>>& adj,int i,vector<int>& col,int curr){
        col[i]=curr;
        for(auto it:adj[i]){
            if(col[it]==col[i]) return false;
            if(col[it]==-1){
                if(isBipartite(adj,it,col,1-curr)==false) return false;
            }
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> col(n+1,-1);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(isBipartite(adj,i,col,1)==false) return -1;
            }
        }
        vector<int> lev(n+1,0);
        for(int i=1;i<=n;i++){
            lev[i]=bfs(adj,i,n);
        }
        int maxi=0;
        vector<bool> vis(n+1,false);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                maxi+=getMaxi(adj,i,vis,lev);
            }
        }
        return maxi;
    }
};
