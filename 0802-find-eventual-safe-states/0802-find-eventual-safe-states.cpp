class Solution {
public:
    
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited){
        if(visited[node] == 2) return true;
        
        visited[node] = 1;
        for(auto child : graph[node]){
            if(visited[child] == 2) continue;
            else if(visited[child] == 1 || !dfs(child,graph,visited)) return false;
        }
        visited[node] = 2;
        return true;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> safes;
        
        for(int i=0 ; i<n ; ++i){
            if(dfs(i,graph,visited)) safes.push_back(i);
        }

        return safes;
    }
};