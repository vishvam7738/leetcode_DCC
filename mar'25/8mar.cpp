class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(blocks[i]=='B'&&blocks[i+1]=='B') cnt++;
            else cnt=0;
            if(cnt>=k) return 0;
        }
        // int cw=0,cb=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cw=0,cb=0;
            for(int j=i;j<n;j++){
                if(blocks[j]=='W') cw++;
                else cb++;
                if(cb+cw==k) ans=min(ans,cw);
            }
        }
        return ans;
    }
};
