class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();            
        int mini = INT_MAX;
        
        for(int i=1 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                    
                if(j == 0)   matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
                else if(j == n-1) matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j-1]);
                else matrix[i][j] += min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i-1][j+1]));
                
            }
        }
        
        for(int j=0 ; j<n ; ++j){
            mini = min(mini,matrix[n-1][j]);
        }
        
        return mini;
        
    }
};