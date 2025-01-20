class Solution {
public:
    bool checkR(vector<vector<int>>& mat,int row){
        for(int col=0;col<mat[0].size();col++){
            if(mat[row][col]>0) return false;
        }
        return true;
    }
    bool checkC(vector<vector<int>>& mat,int col){
        for(int row=0;row<mat.size();row++){
            if(mat[row][col]>0) return false;
        }
        return true;
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,pair<int,int>> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[mat[i][j]]={i,j};
            }
        }
        // for(int i=0;i<arr.size();i++){
        //     int val=arr[i];
        //     auto [row,col]=mpp[val];
        //     mat[row][col]*=-1;
        //     if(checkR(mat,row)||checkC(mat,col)) return i;
        // }

        vector<int> cr(n,0),cc(m,0);
        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            auto [row,col]=mpp[val];
            cr[row]++;cc[col]++;
            if(cr[row]==m||cc[col]==n) return i;
        }
        return -1;
    }
};
