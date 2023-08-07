class Solution {
public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    
    void makecopythreshold(vector<vector<int>> &copy, int threshold){
        
        int n = copy.size();
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(copy[i][j] >= threshold) copy[i][j] = 1;
                else copy[i][j] = -1;
            }
        }
        
        return;
        
    }
    
    bool ispossible(vector<vector<int>> &copy){
        
        int n = copy.size();
        if(copy[0][0] == -1 || copy[n-1][n-1] == -1) return false;
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        q.push({0,0});
        visited[0][0] = true;
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x == n - 1 && y == n - 1) return true;
            
            for(int i=0 ; i<4 ; ++i){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && copy[new_x][new_y] != -1 && !visited[new_x][new_y]){
                    visited[new_x][new_y] = true;
                    q.push({new_x,new_y});
                }           
            }
        
        }
        

        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
           }
        }
        
         
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0 ; i<4 ; ++i){
                
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n){
                    if(dist[new_x][new_y] > 1 + dist[x][y]){
                        dist[new_x][new_y] = 1 + dist[x][y];
                        q.push({new_x,new_y});
                    }
                }                      
            }
        }
        
    
        
        int l = 0;
        int r = n;
        int res = 0;
        
        while(l <= r){
            
            int mid = l + (r - l) / 2;
            vector<vector<int>> copy = dist;
            makecopythreshold(copy,mid);
            
            if(ispossible(copy)){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
            
        }
            
        return res;
        
    }
};