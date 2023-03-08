class Solution {
public:
    
    
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &colors){
        
        for(auto child : graph[node]){
            if(colors[child] == colors[node]) return false;
            if(colors[child] != -1) continue;
            
            colors[child] = !colors[node];
            if(!dfs(child,graph,colors)) return false;
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> graph(n+1);
        
        for(int i=0 ; i<dislikes.size() ; ++i){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> colors(n+1,-1);
        
        for(int i=1 ; i<=n ; ++i){
            if(colors[i] == -1){
                colors[i] = 0;
                if(!dfs(i,graph,colors)) return false;
            }   
        }
        
        return true;
    }
};