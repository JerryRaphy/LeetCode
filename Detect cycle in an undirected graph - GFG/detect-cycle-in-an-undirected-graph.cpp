//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, int parent){
        
        visited[node] = true;
        for(auto child : adj[node]){
            if(!visited[child]){
                if(dfs(child,adj,visited,node)) return true;
            }
            else if(parent != child && visited[child])
                return true;
        }
        visited[node] = false;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,false);
        for(int i=0 ; i<V ; ++i){
            if(!visited[i]){
                if(dfs(i,adj,visited,-1)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends