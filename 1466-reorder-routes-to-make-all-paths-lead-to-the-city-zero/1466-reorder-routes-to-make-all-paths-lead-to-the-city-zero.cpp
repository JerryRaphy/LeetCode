class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        set<int> visited;
        
        vector<vector<pair<int,bool>>> graph(n);
    
        for(int i=0 ; i<m ; ++i){
            graph[connections[i][0]].push_back({connections[i][1],true});
            graph[connections[i][1]].push_back({connections[i][0],false});
        }
        
        visited.insert(0);
        queue<int> q;
        q.push(0);
        int moves = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                int child = it.first;
                bool way = it.second;
                
                if(visited.find(child) != visited.end()) continue;
                if(way) moves += 1;
                visited.insert(child);
                q.push(child);
            }
        }
        
        return moves;
    }
};