class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // int n=nums.size();
        // long long ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             ans=max(ans,(long long)(nums[i]-nums[j])*(long long)nums[k]);
        //         }
        //     }
        // }
        // return ans;

        // int n=nums.size();
        // vector<int> l(n);
        // vector<int> r(n);
        // long long ans=0;
        // for(int i=1;i<n;i++){
        //     l[i]=max(l[i-1],nums[i-1]);
        // }
        // for(int i=n-2;i>=0;i--){
        //     r[i]=max(r[i+1],nums[i+1]);
        // }
        // for(int i=0;i<n;i++){
        //     ans=max(ans,(long long)(l[i]-nums[i])*(long long)(r[i]));
        // }
        // return ans;

        int n=nums.size();
        long long maxi=0,diff=0,ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,diff*nums[i]);
            diff=max(diff,maxi-nums[i]);
            maxi=max(maxi,(long long)nums[i]);
        }
        return ans;
    }
};
