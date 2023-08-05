class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int mx_value = (n * m) + 1;
        
        vector<vector<int>> cost(n,vector<int>(m,mx_value));
        queue<vector<int>> q;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 2){
                    q.push({0,i,j});
                    cost[i][j] = 0;
                }
                else if(grid[i][j] == 0) cost[i][j] = 0;
            }
        }
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {-1,1,0,0};
        
        while(!q.empty()){
            
            int c = q.front()[0];
            int x = q.front()[1];
            int y = q.front()[2];
            
            q.pop();
            
            for(int i=0 ; i<4 ; ++i){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;     
                if(grid[new_x][new_y] != 1) continue;
                
                if(cost[new_x][new_y] > 1 + c){
                    cost[new_x][new_y] = 1 + c;
                    q.push({cost[new_x][new_y],new_x,new_y});
                }
            }
        }
        
        int res = 0;
        
        /*
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) cout<<cost[i][j]<<" ";
            cout<<endl;
        }
        */
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) res = max(res,cost[i][j]);
        }
        
        return res == mx_value ? -1 : res;
    }
};