class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> o(n);
        o[0]=0;
        for(int i=0;i<n-1;i++) o[i+1]=o[i]^derived[i];
        if(o[n-1]^o[0]==derived[n-1]) return true;
        o[0]=1;
        for(int i=0;i<n-1;i++) o[i+1]=o[i]^derived[i];
        if(o[n-1]^o[0]==derived[n-1]) return true;
        return false;
    }
};
