class Solution {
public:
    bool isPossible(int num){
        string s=to_string(num);
        int n=s.size();
        if(n%2) return false;
        int s1=0,s2=0;
        for(int i=0;i<n/2;i++) s1+=int(s[i]);
        for(int i=n/2;i<n;i++) s2+=int(s[i]);
        return s1==s2;
    }
    int countSymmetricIntegers(int low, int high) {
        // int ans=0;
        // for(int i=low;i<=high;i++){
        //     if(isPossible(i)) ans++;
        // }
        // return ans;

        int ans=0;
        for(int i=low;i<=high;i++){
            if(i>=10&&i<=99&&i%11==0) ans++;
            else if(i>=1000&&i<=9999){
                int first=i/1000;
                int second=(i/100)%10;
                int third=(i/10)%10;
                int forth=i%10;
                if(first+second==third+forth) ans++;
            }
        }
        return ans;
    }
};
