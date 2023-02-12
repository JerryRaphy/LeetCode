#define ll long long

class Solution {
public:
    
    
    int dfs(int node, int parent, vector<vector<int>> &graph, int seats, ll &res){
        
        int sub_tree_nodes = 1;
        
        for(auto child : graph[node]){
            if(child != parent){
                sub_tree_nodes += dfs(child,node,graph,seats,res);
            }
        }
        
        if(sub_tree_nodes < seats) res += 1;
        else{
            if(sub_tree_nodes % seats == 0) res += (sub_tree_nodes / seats);
            else res += (sub_tree_nodes / seats) + 1;
        }
        
        return sub_tree_nodes;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        ll res = 0;
        
        for(int i=0 ; i<roads.size() ; ++i){
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        
        for(auto child : graph[0]){
            dfs(child,0,graph,seats,res);
        }
                
        return res;
    }
};