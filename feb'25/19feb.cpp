class Solution {
public:
    void solve(string& s,vector<string>& ans,int n,int k){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!s.empty()&&s.back()==ch) continue;
            s.push_back(ch);
            solve(s,ans,n,k);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string s="";
        solve(s,ans,n,k);
        if(k>ans.size()) return "";
        return ans[k-1];
    }
};
