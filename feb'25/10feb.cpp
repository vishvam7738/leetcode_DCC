class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        stack<char> st;
        // st.push(s[0]);
        for(int i=0;i<n;i++){
            // while(!st.empty()){
                if(isdigit(s[i])) st.pop();
                else st.push(s[i]);
            // }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
