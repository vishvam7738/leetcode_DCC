class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long f=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long s=0;
        long long ans=LONG_LONG_MAX;
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            f-=grid[0][i];
            long long best=max(f,s);
            ans=min(ans,best);
            s+=grid[1][i];
        }
        return ans;
    }
};
