class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        vector<int> f(26,0);
        if(n<k) return false;
        if(n==k) return true;
        for(char ch:s) f[ch-'a']++;
        int of=0;
        for(int i=0;i<26;i++){
            if(f[i]%2!=0) of++;
        }
        return of<=k;
    }
};
