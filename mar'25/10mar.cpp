class Solution {
public:
    bool check(string s,int k){
        int n=s.size();
        // int cnt=0;
        unordered_set<char> st;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i') st.insert(s[i]);
            else cnt2++;
            // if(k>1) return false;
        }
        return (st.size()==5&&cnt2==k);
    }
    long long countOfSubstrings(string s, int k) {
        // int n=word.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(check(word.substr(i,j-i+1),k)) ans++;
        //     }
        // }
        // return ans;

        int n=s.size();
        int l=0,r=0;
        long long ans=0;
        unordered_map<char,int> mpp;
        vector<int> next(n);
        int last=n;
        for(int i=n-1;i>=0;i--){
            next[i]=last;
            if(!(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i')) last=i;
        }
        int cnt=0;
        while(r<n){
            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u') mpp[s[r]]++;
            else cnt++;
            // if(mpp.size()==5&&cnt==k) ans++;
            while(cnt>k){
                // char ch=s[l];
                if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'){
                    mpp[s[l]]--;
                    if(mpp[s[l]]==0) mpp.erase(s[l]);
                }
                else cnt--;
                l++;
            }
            while(l<n&&mpp.size()==5&&cnt==k){
                int idx=next[r];
                ans+=idx-r; //****
                // char ch=s[l];
                if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'){
                    mpp[s[l]]--;
                    if(mpp[s[l]]==0) mpp.erase(s[l]);
                }
                else cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
