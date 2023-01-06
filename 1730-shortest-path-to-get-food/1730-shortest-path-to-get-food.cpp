class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int sx = 0;
        int sy = 0;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == '*'){
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{sx,sy},0});
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {-1,1,0,0};
        
        vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
        
        while(!q.empty()){
            
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            if(grid[x][y] == '#') return dist;
            
            for(int i=0 ; i<4 ; ++i){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
                    
                    if(grid[new_x][new_y] == 'X' || grid[new_x][new_y] == '*') continue;
                
                    if(vis[new_x][new_y] > dist + 1){
                        vis[new_x][new_y] = dist + 1;
                        q.push({{new_x,new_y},dist+1});
                    }
                    
                }
            }  
        }
        return -1;  
    }
};