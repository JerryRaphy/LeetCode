class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        long long res = 0;
        vector<bool> rows(n,false);
        vector<bool> cols(n,false);
        
        
        int n_cols = n;
        int n_rows = n;
        
        for(int i=queries.size()-1 ; i>=0 ; --i){
            if(queries[i][0] == 0 && !rows[queries[i][1]]){
                 rows[queries[i][1]] = true;
                 n_rows -= 1;
                 res += (n_cols * queries[i][2]);
            }
            else if(queries[i][0] == 1 && !cols[queries[i][1]]){
                 cols[queries[i][1]] = true;
                 n_cols -= 1;
                 res += (n_rows * queries[i][2]);
            } 
        }
        
        return res;
    }
};