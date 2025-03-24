bool comp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
}
class Solution {
public:
    // bool comp(vector<int> &a,vector<int> &b){
    //     return a[0]<b[0];
    // }
    int countDays(int days, vector<vector<int>>& m) {
        int n=m.size();
        sort(m.begin(),m.end(),comp);
        int ans=0;
        ans+=abs(m[0][0]-1);
        for(int i=1;i<n;i++){
            if(m[i][0]<=m[i-1][1]){
                if(m[i][1]<m[i-1][1]) m[i][1]=m[i-1][1];
            }
            else{
                int dy=m[i][0]-m[i-1][1];
                ans+=dy-1;
            }
        }
        ans+=abs(m[n-1][1]-days);
        return ans;
    }
};
