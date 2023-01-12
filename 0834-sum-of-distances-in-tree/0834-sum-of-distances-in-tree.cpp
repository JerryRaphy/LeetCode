class Solution {
public:
    
    vector<int> cnt;
    vector<int> res;
    vector<vector<int>> graph;
    
    
    void dfs1(int node, int par){
        
        for(auto child : graph[node]){
            if(child == par) continue;
            dfs1(child,node);
            cnt[node] += cnt[child];
            res[node] += res[child] + cnt[child];
        }
    }   
    
    void dfs2(int node, int par){
        for(auto child : graph[node]){
            if(child == par) continue;
            res[child] = res[node] - cnt[child] + (cnt.size() - cnt[child]); 
            dfs2(child,node);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        graph.resize(n);
        
        for(int i=0 ; i<edges.size() ; ++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        cnt.resize(n,1);
        res.resize(n,0);
        
        dfs1(0,-1);
        dfs2(0,-1);
        
        return res;
    }
};