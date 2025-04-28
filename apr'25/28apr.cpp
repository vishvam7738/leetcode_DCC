class Solution {
public:
    int score(vector<int>& nums,int start,int end){
        long long sum=0;
        for(int i=start;i<=end;i++){
            sum+=nums[i];
        }
        return sum*1LL*(end-start+1);
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        // int n=nums.size();
        // long long ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(score(nums,i,j)<k) ans++;
        //     }
        // }
        // return ans;

        int n=nums.size();
        long long ans=0;
        int l=0,r=0;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            // if(sum*(r-l+1)<k){
            //     ans+=(r-l+1);
            // }
            while(sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};
