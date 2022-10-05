class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> col(n,vector<int>(m,0));
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(j == 0) col[i][j] = grid[i][j];
                else col[i][j] = col[i][j-1] + grid[i][j];
            }
        }
        
       
        int mx = 0;       
        for(int i=0 ; i<=n-3 ; ++i){
            for(int j=0 ; j<=m-3 ; ++j){
                int f = col[i][j+2] + grid[i+1][j+1] + col[i+2][j+2];
                if(j-1 >= 0) f -= col[i][j-1] + col[i+2][j-1];
                mx = max(mx,f);
            }
        }
        return mx;
        
        
    }
};