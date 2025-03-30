class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp1;
        unordered_map<char,int> mp2;
        int cnt=0,flag=0;
        vector<int> result;
        for(auto c:s){
            mp1[c]++;
        }
        for(int i=0;i<s.size();i++){
            mp2[s[i]]++;
            cnt++;
            flag=1;
            for(auto it:mp2){
                if(it.second!=mp1[it.first]) flag=0;
            }
                if(flag){
                    mp2.clear();
                    result.push_back(cnt);
                    cnt=0;
                }
        }
        return result;
    }
};
