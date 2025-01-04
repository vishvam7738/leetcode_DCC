class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // int n=s.size();
        // unordered_set<char> st;
        // int ans=0;
        // for(int i=0;i<n;i++) st.insert(s[i]);
        // for(char ch: st){
        //     int l=-1,r=-1;
        //     for(int i=0;i<n;i++){
        //         if(ch==s[i]){
        //             if(l==-1) l=i;
        //             r=i;
        //         }
        //     }
        //     unordered_set<char> st1;
        //     for(int m=l+1;m<r;m++){
        //         st1.insert(s[m]);
        //     }
        //     ans+=st1.size();
        // }
        // return ans;

        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (indices[idx].first == -1) {
                indices[idx].first = i;
            }

            indices[idx].second = i;
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (indices[i] == make_pair(-1, -1)) {
                continue;
            }

            unordered_set<char> st;
            for (int middle = indices[i].first + 1;
                 middle <= indices[i].second - 1; middle++) {

                st.insert(s[middle]);
            }

            result += st.size();
        }

        return result;
    }
};
