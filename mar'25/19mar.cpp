class Solution {
public:
    int minOperations(vector<int>& nums) {
        // int n=nums.size();
        // int ans=0;
        // // if(n%3) return -1;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0&&j+2<n){
        //             nums[j]=!nums[j];
        //             nums[j+1]=!nums[j+1];
        //             nums[j+2]=!nums[j+2];
        //             ans++;
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0) return -1;
        // }
        // return ans;

        int n=nums.size();
        int ans=0;
        int r=0;
        while(r<n){
            if(nums[r]==0&&r+2<n){
                nums[r]=!nums[r];
                nums[r+1]=!nums[r+1];
                nums[r+2]=!nums[r+2];
                ans++;
            }
            r++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) return -1;
        }
        return ans;
    }
};
