class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> b,c;
        vector<int> ans;
        int cnt=0;
        for(auto it:queries){
            int pos=it[0],col=it[1];
            if(b.count(pos)>0){
                if(--c[b[pos]]==0) cnt--;
            }
            b[pos]=col;
            if(++c[col]==1) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};
