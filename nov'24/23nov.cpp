class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>> res(n,vector<char> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=box[j][i];
            }
        }

        for(vector<char>& row:res){
            reverse(row.begin(),row.end());
        }

        // for(int j=0;j<m;j++){
        //     for(int i=n-1;i>=0;i--){
        //         if(res[i][j]=='.'){
        //             int s=-1;
        //             for(int k=i-1;k>=0;k--){
        //                 if(res[k][j]=='*') break;
        //                 else if(res[k][j]=='#'){
        //                     s=k;
        //                     break;
        //                 }
        //             }
        //             if(s!=-1){
        //                 res[i][j]='#';
        //                 res[s][j]='.';
        //             }
        //         }
        //     }
        // }

        for(int j=0;j<m;j++){
            int s=n-1;
            for(int i=n-1;i>=0;i--){
                if(res[i][j]=='*'){
                    s=i-1;
                    continue;
                }
                if(res[i][j]=='#'){
                    res[i][j]='.';
                    res[s][j]='#';
                    s--;
                }
            }
        }
        return res;
    }
};
