class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(),banned.end());
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()&&i<=maxSum){
                cnt++;
                maxSum-=i;
            }
            else if(i>maxSum) break;
        }
        return cnt;
    }
};
