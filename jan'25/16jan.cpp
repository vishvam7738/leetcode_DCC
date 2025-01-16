class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        // vector<int> n;
        // int ans=0;
        // for(int i=0;i<n1;i++){
        //     for(int j=0;j<n2;j++){
        //         // n.push_back(nums1[i]^nums2[j]);
        //         ans^=nums1[i]^nums2[j];
        //     }
        // }
        // // for(int i=0;i<n.size();i++){
        // //     ans^=n[i];
        // // }
        // return ans;

        int x1=0,x2=0;
        if(n1%2!=0){
            for(int n:nums2) x1^=n;
        }
        if(n2%2!=0){
            for(int n:nums1) x2^=n;
        }
        return x1^x2;
    }
};
