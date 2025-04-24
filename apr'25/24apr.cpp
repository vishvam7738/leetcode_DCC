class Solution {
public:
    int findDistinct(vector<int>& nums,int n,int start,int end){
        unordered_set<int> st;
        for(int i=start;i<=end;i++) st.insert(nums[i]);
        return st.size();
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=findDistinct(nums,n,0,n-1);
        int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int dis=findDistinct(nums,n,i,j);
        //         if(dis==cnt) ans++;
        //         if(dis>cnt) break;
        //     }
        // }
        int l=0,r=0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()==cnt){
                ans+=n-r;
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
