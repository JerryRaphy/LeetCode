const int mod = 1e9 + 7;

class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int i, int j, vector<vector<int>> &freq, string &target){
        
        if(j == target.length()) return 1;
        if(i == freq.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j] % mod;
        
        // skip this index go to the next one
        int skippedways = solve(i+1,j,freq,target) % mod;
        
        int useways = 0;
        char ch = target[j];
        
        if(freq[i][ch - 'a'] != 0){
            int pickways = freq[i][ch - 'a'];
            int nextways = solve(i+1,j+1,freq,target) % mod;
            useways = (pickways%mod * (long long)nextways%mod) % mod;
        }
        
        return dp[i][j] = (useways%mod + (long long)skippedways%mod) % mod;
    }
    
    int numWays(vector<string>& words, string target) {
        
        int n = words.size();
        int m = words[0].size();
        int l = target.length();
        
        dp.resize(m,vector<int>(l,-1));
        vector<vector<int>> freq(m,vector<int>(26,0));
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                char ch = words[i][j];
                freq[j][ch - 'a'] += 1;
            }
        }
        
        return solve(0,0,freq,target) % mod;
    }
};