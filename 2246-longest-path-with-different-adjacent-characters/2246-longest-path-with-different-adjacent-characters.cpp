class Solution {
public:
    
    
    int dfs(int node, vector<vector<int>> &graph, string &s, int &max_path){
               
        int max_len_1 = 0;
        int max_len_2 = 0;
        
        for(int child : graph[node]){
            
            int curr_len = dfs(child,graph,s,max_path);
            if(s[node] == s[child]) continue;
            
            if(curr_len > max_len_1){
                max_len_2 = max_len_1;
                max_len_1 = curr_len;
            }
            else if(curr_len > max_len_2) max_len_2 = curr_len;
        
        }
        
        max_path = max(max_path,max_len_1 + max_len_2 + 1);
        return max_len_1 + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        int max_path = 1;
        
        vector<vector<int>> graph(n+1);
        for(int i=1 ; i<n ; ++i){
                graph[parent[i]].push_back(i);
        }
        
        dfs(0,graph,s,max_path);
        return max_path;
    }
};