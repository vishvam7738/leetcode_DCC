class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum%2) ans++;
        //     }
        // }
        // return ans;
        const int MOD=1e9+7;
        int n=arr.size();
        vector<int> pre(n+1,0);
        pre[0]=0;
        int sum=0;
        for(int i=1;i<n+1;i++){
            sum+=arr[i-1];
            pre[i]+=sum;
        }
        for(auto it:pre) cout<<it<<endl;
        int even=0,odd=0,ans=0;
        for(int i=0;i<pre.size();i++){
            if(pre[i]%2==0){
                even++;
                ans+=odd;
            }
            else{
                odd++;
                ans=(ans+even)%MOD;
            }
        }
        return ans%MOD;
    }
};
