class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> ps(n-1,0);
        for(int i=0;i<n-1;i++){
            ps[i]=weights[i]+weights[i+1];
        }
        sort(ps.begin(),ps.end());
        long long ans=0;
        long long mini=0,maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=ps[i];
            maxi+=ps[n-i-2];
        }
        ans=maxi-mini;
        return ans;
    }
};
