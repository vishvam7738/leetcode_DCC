class Solution {
public:
    bool solve(string s, string t){
        if((t.substr(0,s.size())==s)&&(t.substr(t.size()-s.size(),s.size())==s)) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=i+1;j<n;j++){
                string t=words[j];
                if(solve(s,t)) ans++;
            }
        }
        return ans;
    }
};
