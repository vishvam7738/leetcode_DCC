class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<n;j++){
                string t=words[j];
                for(int k=0;k<t.size();k++){
                    if(i!=j&&t.substr(k,s.size())==s) st.insert(s);
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
