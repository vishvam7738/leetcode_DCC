class Solution {
public:
    int maxi(vector<int>& nums,int start,int end){
        int ans=INT_MIN;
        for(int i=start;i<=end;i++){
            ans=max(ans,nums[i]);
        }
        return ans;
    }
    int mini(vector<int>& nums,int start,int end){
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans,nums[i]);
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // int n=nums.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int mini=INT_MAX;
        //     int maxi=INT_MIN;
        //     for(int j=i;j<n;j++){
        //         // if(mini(nums,i,j)==minK&&maxi(nums,i,j)==maxK) ans++;
        //         mini=min(mini,nums[j]);
        //         maxi=max(maxi,nums[j]);
        //     }
        //     if(mini==minK&&maxi==maxK) ans++;
        // }
        // return ans;

        int miniPos=-1,maxiPos=-1,culprit=-1;
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==minK) miniPos=i;
            if(nums[i]==maxK) maxiPos=i;
            if(nums[i]>maxK||nums[i]<minK) culprit=i;
            long long temp=min(miniPos,maxiPos)-culprit;
            ans+=(temp<=0)?0:temp;
        }
        return ans;
    }
};
