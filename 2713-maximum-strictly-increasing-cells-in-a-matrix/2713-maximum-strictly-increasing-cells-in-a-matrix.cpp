class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> row(n,-1);
        vector<int> col(m,-1);
        
        vector<vector<int>> grid(n,vector<int>(m,0));    
        vector<vector<int>> v;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                v.push_back({mat[i][j],i,j});
            }
        }
        
        sort(v.rbegin(),v.rend());
        int sz = n * m;
        
    
        
        int i = 0;
        while(i < sz){
            int j = i + 1;
            while(j < sz && v[j][0] == v[i][0]) j += 1;
            

            for(int k=i ; k<j ; ++k){
                int r = v[k][1];
                int c = v[k][2];
                int val = v[k][0];
                
                grid[r][c] = 1 + max(row[r],col[c]);
            }
            
            for(int k=i ; k<j ; ++k){
                int r = v[k][1];
                int c = v[k][2];
                
                row[r] = max(row[r],grid[r][c]);
                col[c] = max(col[c],grid[r][c]);
            }
        
            i = j;
        }
        
        
        int res = 0;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) res = max(res,grid[i][j]);
        }
        
        return res + 1;
    }
};