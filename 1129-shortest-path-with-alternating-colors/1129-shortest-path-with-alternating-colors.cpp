class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& rededges, vector<vector<int>>& blueedges) {
        
        vector<int> res(n,-1);
        vector<vector<pair<int,int>>> graph(n);
        
        // 1 -> blue
        // 0 -> red
        
        for(int i=0 ; i<rededges.size() ; ++i)  graph[rededges[i][0]].push_back({rededges[i][1],0});
        for(int i=0 ; i<blueedges.size() ; ++i) graph[blueedges[i][0]].push_back({blueedges[i][1],1});
        
        vector<vector<bool>> visited(n,vector<bool>(2,false));
        queue<pair<pair<int,int>,int>> q;
        // node , dist , color
        
        q.push({{0,0},-1});
        res[0] = 0;
        visited[0][0] = true;
        visited[0][1] = true;
        
        while(!q.empty()){
            int node   =  q.front().first.first;
            int dist   =  q.front().first.second;
            int color  =  q.front().second;
            q.pop();
            
            for(auto children : graph[node]){
                int child = children.first;
                int child_color = children.second;
                
                if(color != child_color){
                    if(visited[child][child_color] == false){
                        visited[child][child_color] = true;
                        q.push({{child,dist + 1},child_color});
                        
                        if(res[child] == -1) res[child] = dist + 1;
                        else res[child] = min(res[child],dist + 1);
                    }
                }
            }
        }
        
        return res;
    }
};