class Solution {
public:
    
    vector<vector<int>> freq;
    vector<int> res;
    vector<bool> visited;
    
    
    void dfs(int node, int n, vector<vector<int>> &graph, string &labels){
        
        // make it visited
        visited[node] = true;
         
        for(auto child : graph[node]){
            
            if(!visited[child]){
                dfs(child,n,graph,labels);
                
                for(int i=0 ; i<26 ; ++i){
                    freq[node][i] += freq[child][i]; 
                }
                res[node] += freq[child][labels[node] - 'a'];
            }
        }
        
        freq[node][labels[node] - 'a'] += 1;
        res[node] += 1;
        
        return;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        int m = edges.size();
        vector<vector<int>> graph(n);
        
        freq.resize(n,vector<int>(26,0));
        res.resize(n,0);
        visited.resize(n,false);
        
        for(int i=0 ; i<m ; ++i){
            graph[edges[i][0]].push_back(edges[i][1]);  
            graph[edges[i][1]].push_back(edges[i][0]);
        }   
        
        dfs(0,n,graph,labels);
        return res;
    }
};