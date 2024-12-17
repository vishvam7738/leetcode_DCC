class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> f(26,0);
        int i=25;
        for(char ch: s){
            f[ch-'a']++;
        }
        string ans;
        while(i>=0){
            if(f[i]==0){
                i--;
                continue;
            }
            char ch='a'+i;
            int freq=min(f[i],repeatLimit);
            ans.append(freq,ch);
            f[i]-=freq;
            if(f[i]>0){
                int j=i-1;
                while(j>=0&&f[j]==0){
                    j--;
                }
                if(j<0){
                    break;
                }
                ans.push_back('a'+j);
                f[j]--;
            }
        }
        return ans;
    }
};
