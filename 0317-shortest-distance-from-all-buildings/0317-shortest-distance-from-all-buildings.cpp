class Solution {
public:
    
    
    void bfs(int st, int en, int n, int m, vector<vector<int>> &grid, vector<vector<pair<int,int>>> &dist){
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<pair<int,int>> moves = {{0,1},{0,-1},{-1,0},{1,0}};
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{st,en},0});
        
        while(!q.empty()){
            int x   = q.front().first.first;
            int y   = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            // for an empty cell 
            if(grid[x][y] == 0){
                dist[x][y].first  += 1;
                dist[x][y].second += dis;
            }
            
            for(int i=0 ; i<4 ; ++i){
                int new_x = x + moves[i].first;
                int new_y = y + moves[i].second;
                
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
                    if(grid[new_x][new_y] == 1 || grid[new_x][new_y] == 2 || (grid[new_x][new_y] == 0 && vis[new_x][new_y])) continue;
                    vis[new_x][new_y] = true;
                    q.push({{new_x,new_y},dis+1});
                }
            }
        }
        
        return;
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int,int>>> dist(n,vector<pair<int,int>>(m,{0,0}));
        
        int number_of_houses = 0;
        int mindist = INT_MAX;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                
                // if we have found a building begin bfs now
                if(grid[i][j] == 1){
                    ++number_of_houses;
                    bfs(i,j,n,m,grid,dist);
                }
            }
        }
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(dist[i][j].first == number_of_houses){
                    mindist = min(mindist,dist[i][j].second);
                }
            }
        }
        
        return mindist == INT_MAX ? -1 : mindist;
    }
};