class Solution {
public:
    
    /*
    void makedist(vector<vector<int>> &dist, int threshold){
        
        int n = dist.size();
        int m = dist[0].size();
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                
                int l = INT_MAX, r = INT_MAX, d = INT_MAX, u = INT_MAX;
                
                if(j - 1 >= 0) l = abs(heights[i][j] - heights[i][j-1]);
                if(j + 1 < m)  r = abs(heights[i][j] - heights[i][j+1]);
                if(i - 1 >= 0) u = abs(heights[i][j] - heights[i-1][j]);
                if(i + 1 < n)  d = abs(heights[i][j] - heights[i+1][j]);
                
                int curr = 
                 
            }
        }
        
    }
    */
    
    
    bool ispossible(vector<vector<int>> &heights, int threshold){
        
        int n = heights.size();
        int m = heights[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        q.push({0,0});
        visited[0][0] = true;
        
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x == n - 1 && y == m - 1) return true;
            
            for(int i=0 ; i<4 ; ++i){
                
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !visited[new_x][new_y]){
                    if(abs(heights[x][y] - heights[new_x][new_y]) <= threshold){
                        visited[new_x][new_y] = true;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        int l = 0;
        int r = 1e6 + 1;
        int res = r;
        
        while(l <= r){
            
            int mid = l + (r - l) / 2;
            if(ispossible(heights,mid)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
            
        }
        
        return res;
    }   
};