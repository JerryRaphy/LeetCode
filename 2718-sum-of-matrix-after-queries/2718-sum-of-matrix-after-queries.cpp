class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        long long res = 0;
        int rows = n;
        int cols = n;
        
        vector<bool> r(n,false);
        vector<bool> c(n,false);
        
        int m = queries.size();
        for(int i=m-1 ; i>=0 ; --i){
            if(queries[i][0] == 0 && !r[queries[i][1]]){
                res += (queries[i][2] * cols);
                r[queries[i][1]] = true;
                rows -= 1;
            }
            else if(queries[i][0] == 1 && !c[queries[i][1]]){
                res += (queries[i][2] * rows);
                c[queries[i][1]] = true;
                cols -= 1;
            }
        }
        
        return res;
    }
};