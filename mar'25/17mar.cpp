class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n-1;i+=2){
        //     if(nums[i]!=nums[i+1]) return false;
        // }
        // return true;
        sort(nums.begin(), nums.end());
        int i = 1;
        while(i < nums.size()){
            if(nums[i-1] != nums[i]){
                return false;
            }
            i += 2;
        }
        return true;
    }
};
