class Solution {
public:
    bool check(string& ans,string& pattern){
        for(int i=0;i<pattern.size();i++){
            if((pattern[i]=='I'&&ans[i]>ans[i+1])||(pattern[i]=='D'&&ans[i]<ans[i+1])) return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string ans="";
        for(int i=1;i<=n+1;i++){
            ans.push_back(i+'0');
        }
        while(!check(ans,pattern)) next_permutation(ans.begin(),ans.end());
        return ans;
    }
};
