class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),ans=0,maxi=0;
        for(int i=0;i<n;i++){
            // if(maxi<arr[i]){
            //     maxi=arr[i];
            // }
            maxi=max(maxi,arr[i]);
            if(maxi==i) ans++;
        }
        return ans;
    }
};
