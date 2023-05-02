class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto road : roads){
            graph[road[0]].push_back({road[1],road[2]});
            graph[road[1]].push_back({road[0],road[2]});
        }
        
        queue<pair<int,int>> q;
        vector<int> visited(n+1,INT_MAX);
        visited[1] = INT_MAX;
        q.push({1,INT_MAX});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int mini = q.front().second;
            q.pop();
            
            for(auto child : graph[node]){
                int mn = min(mini,child.second);
                if(mn < visited[child.first]){
                    visited[child.first] = mn;
                    q.push({child.first,visited[child.first]});
                }
            }
        }        
        
        return visited[n];
    }
};