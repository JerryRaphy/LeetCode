class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        const int mod = 12345;
        
        vector<vector<int>> res(n,vector<int>(m));
        vector<vector<int>> prefix(n,vector<int>(m));
        vector<vector<int>> suffix(n,vector<int>(m));
        
        
        long long p = 1;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                prefix[i][j] = p % mod;
                p = (p * grid[i][j]);
                p %= mod;
            }
        }
        
        long long s = 1;
        for(int i=n-1 ; i>=0 ; --i){
            for(int j=m-1 ; j>=0 ; --j){
                suffix[i][j] = s % mod;
                s = (s * grid[i][j]);
                s %= mod;
            }
        }
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                res[i][j] = (prefix[i][j]%mod * suffix[i][j]%mod) % mod;
            }
        }
        
        return res;
    }
};