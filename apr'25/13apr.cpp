class Solution {
public:
    long long MOD=1e9+7;
    long long pow(long long x, long long n){
        if(n==0) return 1;
        long long temp=pow(x,n/2);
        if(n%2==0) return (temp*temp)%MOD;
        else return (x*temp*temp)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

        long long first=pow(5,even)%MOD;
        long long second=pow(4,odd)%MOD;
        return (int)((first*second)%MOD);
    }
};
