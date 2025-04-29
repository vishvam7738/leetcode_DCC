class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // int n=nums.size();
        // int maxi=INT_MIN;
        // int ans=0;
        // for(int i=0;i<n;i++) maxi=max(maxi,nums[i]);
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==maxi) cnt++;
        //         if(cnt>=k) ans++;
        //     }
        // }
        // return ans;

        int n=nums.size();
        int l=0,r=0;
        long long ans=0;
        int maxi=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++) maxi=max(maxi,nums[i]);
        while(r<n){
            if(nums[r]==maxi) cnt++;
            while(cnt>=k){
                ans+=(n-r);
                if(nums[l]==maxi) cnt--;
                l++;
            }
            // else{
            //     if(nums[l]==maxi) cnt--;
            //     l++;
            // }
            r++;
        }
        return ans;
    }
};
