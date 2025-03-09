class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // int ind=0;
        // int n=colors.size();
        // for (int i = 0; i < k - 1; i++) {
        //     colors.push_back(colors[i]);
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     bool flag=true;
        //     for(int j=i;j<i+k-1;j++){
        //         if(colors[j]==colors[j+1]){
        //             flag=false;
        //             break;
        //         }
        //         // else ans++;
        //     }
        //     if(flag) ans++;
        // }
        // return ans;

        int n=colors.size();
        int N=n+(k-1);
        for(int i=0;i<k-1;i++) colors.push_back(colors[i]);
        int ans=0,l=0,r=1;
        while(r<N){
            if(colors[r]==colors[r-1]){
                l=r;
                r++;
                continue;
            }
            if(r-l+1==k){
                ans++;
                l++;
            }
            r++;
        }
        return ans;
    }
};
