class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // int n=nums.size();
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         ans=max(ans,abs(sum));
        //     }
        //     // int s=abs(sum);
        // }
        // return ans;

        int c1=0,c2=0,m1=0,m2=0;
        for(auto it:nums){
            c1+=it;
            m1=max(m1,c1);
            if(c1<0) c1=0;

            c2+=it;
            m2=min(m2,c2);
            if(c2>0) c2=0;
        }
        return max(m1,abs(m2));
    }
};
