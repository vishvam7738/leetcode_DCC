class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        string s="";
        int x=0;
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                x++;
                s="";
            }
            else  s+=sentence[i];
            // cout<<s<<endl;
            if (s.size() >= searchWord.size() && s.substr(0, searchWord.size()) == searchWord) {
                return x + 1;
            }
        }
         x++;
        if (s.size() >= searchWord.size() && s.substr(0, searchWord.size()) == searchWord) {
            return x;
        }
        return -1;
    }
};
