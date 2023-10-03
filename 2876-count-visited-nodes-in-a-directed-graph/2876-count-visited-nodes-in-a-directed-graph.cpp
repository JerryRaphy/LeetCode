class Solution {
public:
    
    void dfs(int node, vector<int> &edges, vector<int> &res, vector<bool> &visited){
        
        if(res[node] != -1) return;
        
        if(visited[node]){
            // get cycle length    
            int temp = node;
            int len = 1;
            while(edges[temp] != node){
                temp = edges[temp];
                len += 1;
            }
            
            // assign all the nodes of cycle same length
            temp = node;
            while(edges[temp] != node){
                res[temp] = len;
                temp = edges[temp];
            }
            res[temp] = len;
            
            return;
        }
        
        visited[node] = true;
        dfs(edges[node],edges,res,visited);
        if(res[node] == -1) res[node] = res[edges[node]] + 1;
        visited[node] = false;
        
        return;
    }
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        
        int n = edges.size();
        vector<int> res(n,-1);
        vector<bool> visited(n,false);
        
        for(int i=0 ; i<n ; ++i){
            dfs(i,edges,res,visited);
        }
        
        return res;
    }
};