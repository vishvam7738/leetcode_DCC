class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini=0,maxi=0,curr=0;
        for(auto it:differences){
            curr+=it;
            maxi=max(maxi,curr);
            mini=min(mini,curr);
            if((upper-maxi)-(lower-mini)+1<=0) return 0;
        }
        return (upper-maxi)-(lower-mini)+1;
    }
};
