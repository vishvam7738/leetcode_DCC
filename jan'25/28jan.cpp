class Solution {
public:
    // int dfs(int i,int j,vector<vector<int>>& grid){
    //     int n=grid.size(),m=grid[0].size();
    //     int cnt=grid[i][j];
    //     grid[i][j]=0;
    //     int x[4]={-1,+1,0,0};
    //     int y[4]={0,0,-1,+1};
    //     for(int d=0;d<4;d++){
    //         int nx=x[d]+i;
    //         int ny=y[d]+j;
    //         if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!=0) cnt+=dfs(nx,ny,grid);
    //     }
    //     return cnt;
    // }
    int bfs(int i,int j,vector<vector<int>>& grid){
        int cnt=grid[i][j];
        int n=grid.size(),m=grid[0].size();
        grid[i][j]=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            int dx[4]={-1,+1,0,0};
            int dy[4]={0,0,-1,+1};
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!=0){
                    cnt+=grid[nx][ny];
                    q.push({nx,ny});
                    grid[nx][ny]=0;
                }
            }
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ans=max(ans,bfs(i,j,grid));
                }
            }
        }
      
