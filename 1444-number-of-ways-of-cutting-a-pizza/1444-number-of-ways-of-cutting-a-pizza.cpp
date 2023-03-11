const int mod = 1e9 + 7;

class Solution {
public:
    
    
    vector<vector<vector<int>>> dp;
    
    
    int solve(int row, int col, int k, vector<vector<int>> &prefix, int n, int m){
        
        if(k == 0) return 1;
        long long int curr = 0;
        
        
        if(dp[row][col][k] != -1) return dp[row][col][k];
        
        // horizontal cuts
        for(int i=row ; i<n ; ++i){
            if(prefix[row][col] - prefix[i][col] > 0 && prefix[i][col] > 0){
                curr += solve(i,col,k-1,prefix,n,m) % mod;
            }
        }
        
        // vertical cuts
        for(int j=col ; j<m ; ++j){
            if(prefix[row][col] - prefix[row][j] > 0 && prefix[row][j] > 0){
                curr += solve(row,j,k-1,prefix,n,m) % mod;
            }
        }
        
        
        return dp[row][col][k] = int(curr % mod);
    }
    
    int ways(vector<string>& pizza, int k) {
        
        int n = pizza.size();
        int m = pizza[0].length();
        
        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
        
        for(int i=n-1 ; i>=0 ; --i){
            for(int j=m-1 ; j>=0 ; --j){
                prefix[i][j] = prefix[i+1][j] + prefix[i][j+1] - prefix[i+1][j+1];
                if(pizza[i][j] == 'A') prefix[i][j] += 1;
            }
        }
        
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
        /*for(int i=0 ; i<=n ; ++i){
            for(int j=0 ; j<=m ; ++j) cout<<prefix[i][j]<<" ";
            cout<<endl;
        }*/
        
        
        return solve(0,0,k-1,prefix,n,m);
        
    }
};