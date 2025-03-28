// class Solution {
// public:
//     void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int& cnt,int n,int m,int que){
//         vis[r][c]=1;
//         int dx[4]={-1,1,0,0};
//         int dy[4]={0,0,-1,1};
//         if(grid[r][c]>que) return;
//         if(grid[r][c]<que) cnt++;
//         for(int i=0;i<4;i++){
//             int nx=r+dx[i];
//             int ny=c+dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&grid[nx][ny]<que){
//                 dfs(nx,ny,grid,vis,cnt,n,m,que);
//             }
//         }
//     }
//     void bfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int& cnt,int n,int m,int que){
//         queue<pair<int,int>> q;
//         if(grid[r][c]<que) q.push({r,c});
//         vis[r][c]=1;
//         int dx[4]={-1,1,0,0};
//         int dy[4]={0,0,-1,1};
//         while(!q.empty()){
//             int x=q.front().first;
//             int y=q.front().second;
//             q.pop();
//             if(grid[x][y]<que) cnt++;
//             for(int i=0;i<4;i++){
//                 int nx=x+dx[i];
//                 int ny=y+dy[i];
//                 if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]<que&&!vis[nx][ny]){
//                     vis[nx][ny]=1;
//                     q.push({nx,ny});
//                 }
//             }
//         }
//     }
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int n=grid.size(),m=grid[0].size();
//         vector<int> ans;
//         for(auto it:queries){
//             vector<vector<int>> vis(n,vector<int>(m,0));
//             int cnt=0;
//             dfs(0,0,grid,vis,cnt,n,m,it);
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int, int>> sortedQ;
        for(int i = 0; i < Q; i++) {
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;


        for(int i = 0; i < Q; i++) {
            int queryValue = sortedQ[i].first;
            int idx        = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < queryValue) {
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }
        
        return result;
    }
};
