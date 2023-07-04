class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int unguardedcells = 0;
        vector<vector<int>> grid(n,vector<int>(m,-1));
        vector<bool> col(m,false);
        
        for(auto guard : guards) grid[guard[0]][guard[1]] = 1;
        for(auto wall : walls)   grid[wall[0]][wall[1]] = 2;
        
        for(int i=0 ; i<n ; ++i){
            bool from_left = false;
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 1){
                     from_left = true;
                     col[j] =  true;                            
                }
                else if(grid[i][j] == 2){
                     from_left = false;
                     col[j] = false;   
                }
                else{
                    if(from_left || col[j]) grid[i][j] = 3;
                }
            }
        }
        
        col.resize(m,false);
        for(int i=n-1 ; i>=0 ; --i){
            bool from_right = false;
            for(int j=m-1 ; j>=0 ; --j){
                if(grid[i][j] == 3) continue;
                else if(grid[i][j] == 1){
                    from_right = true;
                    col[j] = true;
                }
                else if(grid[i][j] == 2){
                    from_right = false;
                    col[j] = false;
                }
                else if(from_right || col[j]) grid[i][j] = 3;
            }
        }
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == -1) unguardedcells += 1;
            }
        }
        
        
        return unguardedcells;
        
        
        
    }
};