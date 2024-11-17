class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0;
        vector<long long> sum(n,0);
        deque<int> dq;
        while(i<n){
            if(i==0) sum[i]=nums[i];
            else sum[i]=sum[i-1]+nums[i];
            if(sum[i]>=k) ans=min(ans,i+1);
            while(!dq.empty()&&sum[i]-sum[dq.front()]>=k){
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty()&&sum[i]<=sum[dq.back()]) dq.pop_back();
            dq.push_back(i);
            i++;
        }
        return ans==INT_MAX?-1:ans;
        // while(i<n){
        //     sum+=nums[i];
        //     while(sum>=k){
        //         if(nums[j]>0) sum-=nums[j];
        //         else sum+=nums[j];
        //         ans=min(ans,i-j+1);
        //         // sum=0;
        //         j++;
        //     }
        //     i++;
        // }
        // return ans==INT_MAX?-1:ans;

        // int n=nums.size();
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum>=k){
        //             ans=min(ans,j-i+1);
        //             break;
        //         }
        //     }
        // }
        // return ans==INT_MAX?-1:ans;
    }
};
