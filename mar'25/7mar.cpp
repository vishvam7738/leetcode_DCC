class Solution {
public:
    vector<bool> sieve(int r){
        vector<bool> isPrime(r+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=r;i++){
            if(isPrime[i]==true){
                for(int j=2;i*j<=r;j++){
                    isPrime[i*j]=false;
                }
            }
        }
        return isPrime;
    }
    // bool check(int num){
    //     for(int i=2;i<num;i++){
    //         if(num%i==0) return false;
    //     }
    //     return true;
    // }
    vector<int> closestPrimes(int left, int right) {
        vector<int> p;
        vector<bool> isPrime=sieve(right);
        for(int i=left;i<=right;i++){
            if(isPrime[i]==true){
                p.push_back(i);
                // if(p.size()==2) break;
            }
        }
        int n=p.size();
        int mini=INT_MAX;
        vector<int> ans(2,-1);
        for(int i=0;i<n-1;i++){
            if(p[i+1]-p[i]<mini){
                mini=p[i+1]-p[i];
                ans[0]=p[i];
                ans[1]=p[i+1];
            }
        }
        return ans;
    }
};
