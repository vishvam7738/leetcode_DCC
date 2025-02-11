class Solution {
public:
    string removeOccurrences(string s, string part) {
        // int n=s.size(),m=part.size();
        // stack<char> st;
        // for(int i=0;i<n;i++){
        //     st.push(s[i]);
        //     if(st.size()>=m){
        //         string temp="";
        //         for(int j=0;j<m;j++){
        //             temp+=st.top();
        //             st.pop();
        //         }
        //         if(temp!=part){
        //             for(char ch:temp) st.push(ch);
        //         }
        //     }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans+=st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;

        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
