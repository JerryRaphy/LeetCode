class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int m = queries.size();
        
        for(int i=0 ; i<m ; ++i){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            
            for(int r=r1 ; r<=r2 ; ++r){
                matrix[r][c1] += 1;
                if(1 + c2 < n) matrix[r][c2+1] -= 1;
            }
        }
        
        for(int i=0 ; i<n ; ++i){
            for(int j=1 ; j<n ; ++j) matrix[i][j] += matrix[i][j-1];
        }
        
        return matrix;
        
    }
};