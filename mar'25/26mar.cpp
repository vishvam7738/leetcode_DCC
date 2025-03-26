class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        int N=nums.size();
        int sum=0;
        int ans=0;
        // for(int i=0;i<N;i++) sum+=nums[i];
        // int s=(N*(N+1))/2;
        // if(s==sum) return -1;
        int mid=nums[0];
        // if(N>1) mid=nums[(N+1)/2];
        if(N%2) mid=nums[N/2];
        else mid=nums[(N+1)/2];
        for(int i=0;i<N;i++){
            // if(nums[i]<mid){
            //     while(nums[i]!=mid){
            //         nums[i]+=x;
            //         ans++;
            //     }
            // }
            // else if(nums[i]>mid){
            //     while(nums[i]!=mid){
            //         nums[i]-=x;
            //         ans++;
            //     }
            // }

            int diff=abs(nums[i]-mid);
            if(diff%x!=0) return -1;
            ans+=(diff/x);
        }
        return ans;
    }
};
