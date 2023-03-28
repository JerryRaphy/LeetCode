class Solution {
public:
    
    
    
    void dfs(int node, int time, int score, vector<vector<pair<int,int>>> &graph, vector<int> &values, vector<int> &visited, int &maxtime, int &maxscore){

        
        if(time > maxtime) return;

        if(visited[node] == 0){
            score += values[node];
        }
        
        visited[node]++;
        
        if(node == 0) 
            maxscore = max(maxscore,score);
        
        for(auto child : graph[node]){
           int new_time = time + child.second;
           dfs(child.first,new_time,score,graph,values,visited,maxtime,maxscore);
        }
        
        visited[node]--;
        return;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxtime) {
        
        int n = values.size();
        vector<vector<pair<int,int>>> graph(n);
        
        for(int i=0 ; i<edges.size() ; ++i){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> visited(n,0);
        int maxscore = 0;
        dfs(0,0,0,graph,values,visited,maxtime,maxscore);
        return maxscore;
        
       
    }
    
};