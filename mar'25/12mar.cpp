class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int ans=INT_MIN;
        int p=0,n=0;
        for(auto it:nums){
            if(it>0) p++;
            else if(it<0) n++; 
        }
        return max(p,n);
    }
};
