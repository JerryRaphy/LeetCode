class Solution {
public:
    
    
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        vector<int> cols(m,0);
        int row_enemies = 0;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                
                //checking along each row now
                if(j == 0 || grid[i][j-1] == 'W'){
                    row_enemies = 0;
                    for(int k=j ; k<m ; ++k){
                        if(grid[i][k] == 'W') break;
                        else if(grid[i][k] == 'E') row_enemies++;
                    }
                }
                
                //checking along the columns
                if(i == 0 || grid[i-1][j] == 'W'){
                    cols[j] = 0;
                    for(int k=i ; k<n ; ++k){
                        if(grid[k][j] == 'W') break;
                        else if(grid[k][j] == 'E') cols[j]++; 
                    }
                }
                
                if(grid[i][j] == '0')cnt = max(cnt,row_enemies + cols[j]);
            }
        }
        return cnt;
    }
};