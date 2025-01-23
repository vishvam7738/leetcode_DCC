class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1){
        //             bool flag=false;
        //             for(int col=0;col<m;col++){
        //                 if(grid[i][col]==1&&col!=j){
        //                     flag=true; 
        //                     break;
        //                 }
        //             }
        //             if(flag){
        //                 ans++;
        //             }
        //             else{
        //                 for(int row=0;row<n;row++){
        //                     if(grid[row][j]==1&&row!=i){
        //                         flag=true; 
        //                         break;
        //                     }
        //                 }
        //                 if(flag) ans++;
        //             }
        //         }
        //     }
        // }
        // return ans;

        vector<int> r(n,0),c(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&(r[i]>1||c[j]>1)) ans++;
            }
        }
        return ans;
    }
};
