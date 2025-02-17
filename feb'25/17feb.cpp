class Solution {
public:
    void solve(int n,string& tiles,string& curr,vector<bool>& used,unordered_set<string>& st){
        st.insert(curr);
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            curr.push_back(tiles[i]);
            used[i]=true;
            solve(n,tiles,curr,used,st);
            used[i]=false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        unordered_set<string> st;
        vector<bool> used(n,false);
        string curr="";
        solve(n,tiles,curr,used,st);
        return st.size()-1;
    }
};
