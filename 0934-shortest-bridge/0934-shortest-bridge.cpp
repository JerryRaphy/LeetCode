class Solution {
public:
    
    void dfs(int x, int y, vector<vector<int>> &grid, int n, int m, vector<vector<bool>> &visited){
        if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 0) return;
        
        grid[x][y] = 2;
        visited[x][y] = true;
        
        dfs(x-1,y,grid,n,m,visited);
        dfs(x+1,y,grid,n,m,visited);
        dfs(x,y-1,grid,n,m,visited);
        dfs(x,y+1,grid,n,m,visited);
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<n ; ++i){
            bool entered = false;
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 1){
                    entered = true;
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                    dfs(i,j,grid,n,m,visited);
                    break;
                }
            }
            if(entered) break;
        }
        
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        /*
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        */
        
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
        
            
            for(int i=0 ; i<4 ; ++i){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
                
                if(dist[new_x][new_y] > dist[x][y] + 1){
                    dist[new_x][new_y] = dist[x][y] + 1;
                    if(grid[new_x][new_y] == 0) q.push({new_x,new_y});
                }
            }
        }
        
        int d = INT_MAX;
        
        /*
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) cout<<dist[i][j]<<" ";
            cout<<endl;
        }
        */
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) {
                if(grid[i][j] == 1) d = min(d,dist[i][j]);
            }
        }
        
        return d - 1;
    }
};