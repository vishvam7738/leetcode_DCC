class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=0,high=1e14;
        while(low<high){
            long long mid=low+(high-low)/2;
            long long rep=0;
            for(auto it:ranks) rep+=sqrt(mid/it);
            if(rep<cars) low=mid+1;
            else high=mid;
        }
        return low;
    }
};
