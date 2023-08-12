class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> time(n,vector<int>(n,INT_MAX));
        time[0][0] = 0;
        
        queue<vector<int>> q;
        q.push({grid[0][0],0,0});
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        while(!q.empty()){
            
            int t = q.front()[0];
            int x = q.front()[1];
            int y = q.front()[2];
            q.pop();
            
            for(int i=0 ; i<4 ; ++i){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x < 0 || new_x >=n || new_y < 0 || new_y >= n) continue;
                
                int time_to_go = t + max(0,grid[new_x][new_y] - t);
                
                if(time_to_go < time[new_x][new_y]){
                    time[new_x][new_y] = time_to_go;
                    q.push({time_to_go,new_x,new_y});
                }
                
            }
        }
        
        return time[n-1][n-1];
        
    }
};