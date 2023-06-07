class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int n = A.size();
        int m = A[0].size();
        int r = B[0].size();
        
        vector<vector<int>> res(n,vector<int>(r,0));
        
        for(int i=0 ; i<n ; ++i){ // all rows in A
            for(int j=0 ; j<r ; ++j){ // all cols in B
                int value = 0;
                for(int k=0 ; k<m ; ++k){  // for each col in A as well as each row in B since both has to be the same
                    value += (A[i][k] * B[k][j]);
                }
                res[i][j] = value;    
            } 
        }
        
        return res;
    }
};