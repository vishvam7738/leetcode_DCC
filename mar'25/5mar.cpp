class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        // for(int i=1;i<n;i++) ans+=4*i;
        return 2LL*n*(n-1)+1;
    }
};
