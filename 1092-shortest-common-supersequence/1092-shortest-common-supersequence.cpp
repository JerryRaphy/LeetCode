class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1 ; i>=0 ; --i){
            for(int j=m-1 ; j>=0 ; --j){
                if(a[i] == b[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        string res;
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(a[i] == b[j]){
                res += b[j];
                i += 1;
                j += 1;
            }
            else if(dp[i][j+1] > dp[i+1][j]){
                res += b[j];
                j += 1;
            }
            else{
                res += a[i];
                i += 1;
            }
        }
        
        while(i < n) res += a[i++];
        while(j < m) res += b[j++];
        
    
        return res;
    
        
    }
};