class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st;
        for(auto &str : supplies){
            st.insert(str);
        }
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> count;
        for(int i=0;i<recipes.size();i++){
            for(auto &str : ingredients[i]){
                if(st.find(str) == st.end()){
                    graph[str].push_back(recipes[i]);
                    count[recipes[i]]++;
                }
            }
        }
        queue<string> q;
        for(auto &str : recipes){
            if(count[str] == 0){
                q.push(str);
            }
        }
        vector<string> ans;
        while(q.size() > 0){
            string curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &ver : graph[curr]){
                count[ver]--;
                if(count[ver] == 0){
                    q.push(ver);
                }
            }
        }
        return ans;
    }
};
