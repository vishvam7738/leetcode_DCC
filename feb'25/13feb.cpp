class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq(nums.begin(),nums.end());
        int ans=0;
        while(!pq.empty()&&pq.top()<k){
            long long n1=pq.top();
            pq.pop();
            long long n2=pq.top();
            pq.pop();
            pq.push((long long)(min(n1,n2)*2+max(n1,n2)));
            // if(pq.top()>=k){
            //     ans++;
            //     break;
            // }
            ans++;
        }
        return ans;
    }
};
