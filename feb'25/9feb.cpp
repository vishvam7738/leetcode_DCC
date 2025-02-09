class Solution {
public:
    typedef long long ll;
    long long countBadPairs(vector<int>& nums) {
        // long long ans=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(j-i!=nums[j]-nums[i]) ans++;
        //     }
        // }
        // return ans;

        unordered_map<int,int> mp;
        ll tot=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            ans+=tot;
            ans-=mp[nums[i]-i];
            mp[nums[i]-i]++;
            tot++;
        }
        return ans;
    }
};
