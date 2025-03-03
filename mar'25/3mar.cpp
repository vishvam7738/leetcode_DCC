class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int> b,a,p;
        // int n=nums.size();
        // for(auto it:nums){
        //     if(it<pivot) b.push_back(it);
        //     else if(it>pivot) a.push_back(it);
        //     else p.push_back(it);
        // }
        // vector<int> ans;
        // for(int i=0;i<b.size();i++) ans.push_back(b[i]);
        // for(int i=0;i<p.size();i++) ans.push_back(p[i]);
        // for(int i=0;i<a.size();i++) ans.push_back(a[i]);
        // return ans;

        int l=0,s=0,h=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) l++;
            else if(nums[i]==pivot) s++;
        }
        h=l+s;
        s=l;
        l=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) ans[l++]=nums[i];
            else if(nums[i]==pivot) ans[s++]=nums[i];
            else ans[h++]=nums[i];
        }
        return ans;
    }
};
