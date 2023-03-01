class Solution {
public:
    
    set<pair<int,int>> st;
    
    
    int dfs(int node, int parent, vector<vector<int>> &graph, vector<bool> &apples){
        
        if(graph[node].size() == 0){
            if(apples[node]) return 1;
            return 0;
        }
        
        int curr = 0;
        
        for(auto child : graph[node]){
            if(child == parent) continue;
            int res = dfs(child,node,graph,apples);
            curr += res;
            if(res) st.insert({node,child});
        } 
        
        if(apples[node]) curr += 1;
        return curr;
        
    }
    
    
    int solve(int node, vector<vector<int>> &graph){
        
        if(graph[node].size() == 0) return 0;
        int t = 0;
        
        for(auto child : graph[node]){
            if(st.find({node,child}) != st.end()){
                t += 2 + solve(child,graph);
            }
        }
        
        return t;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& apples) {
        
        int m = edges.size();
        vector<vector<int>> graph(n);
        
        for(int i=0 ; i<m ; ++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(0,-1,graph,apples);
        return solve(0,graph);
    }
};