class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        // unordered_map<int,int> mpp;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         mpp[grid[i][j]]++;
        //     }
        // }
        // vector<int> ans;
        // for(auto it:mpp){
        //     if(it.second==2) ans.push_back(it.first);
        // }
        // for(int i=1;i<=n*n;i++){
        //     // if(mpp[i]==2) ans.push_back(i);
        //     if(mpp[i]==0) ans.push_back(i);
        // }
        // return ans;

        // int hash[(n*n)+1]={0};
        vector<int> hash(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]++;
            }
        }
        int r=-1,m=-1;
        for(int i=1;i<=n*n;i++){
            if(hash[i]==2) r=i;
            else if(hash[i]==0) m=i;
        }
        return {r,m};
    }
};
