class Solution {
public:
    vector<int> minOperations(string boxes) {
        // int n=s.size();
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     int d=0;
        //     for(int j=0;j<n;j++){
        //         if(i!=j){
        //             if(s[j]=='1') d+=abs(i-j);
        //         }
        //     }
        //     ans.push_back(d);
        // }
        // return ans;

        int n = boxes.size();

        vector<int> answer(n, 0);

        int cumValue    = 0;
        int cumValueSum = 0;

       
        for(int i = 0; i < n; i++) {
            answer[i] = cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        cumValue    = 0;
        cumValueSum = 0;
        
        for(int i = n-1; i >= 0; i--) {
            answer[i] += cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        
        return answer;
    }
};
