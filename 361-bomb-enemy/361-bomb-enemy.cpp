class Solution {
public:
    
    
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        vector<vector<int>> right(n,vector<int>(m,0));
        vector<vector<int>> left(n,vector<int>(m,0));
        vector<vector<int>> down(n,vector<int>(m,0));
        vector<vector<int>> up(n,vector<int>(m,0));
        
        //prefixing for right
        for(int i=0 ; i<n ; ++i){
            for(int j=m-1 ; j>=0 ; --j){
                if(grid[i][j] == 'E') right[i][j] = 1;
                if(grid[i][j] == 'W' || j == m-1) continue;
                right[i][j] += right[i][j+1];
            }
        }
        
        //prefixing for left
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 'E') left[i][j] = 1;
                if(grid[i][j] == 'W' || j == 0) continue;
                left[i][j] += left[i][j-1];
            }
        }
        
        //prefixing for up
        for(int j=0 ; j<m ; ++j){
            for(int i=0 ; i<n ; ++i){
                if(grid[i][j] == 'E') up[i][j] = 1;
                if(grid[i][j] == 'W' || i == 0) continue;
                up[i][j] += up[i-1][j];
            }
        }
        
        
        //prefixing for down
        for(int j=0 ; j<m ; ++j){
            for(int i=n-1 ; i>=0 ; --i){
                if(grid[i][j] == 'E') down[i][j] = 1;
                if(grid[i][j] == 'W' || i == n-1) continue;
                down[i][j] += down[i+1][j];
            }
        }
        
        /*for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) cout<<down[i][j]<<" ";
            cout<<endl;
        }*/
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == '0') {
                    cnt = max(cnt,left[i][j] + up[i][j] + down[i][j] + right[i][j]);
                }
            }
        }
        return cnt;
    }
};