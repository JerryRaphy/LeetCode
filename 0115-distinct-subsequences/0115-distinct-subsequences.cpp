class Solution {
public:
    
    
    int getnumdistinctsubs(int i, int j, string s, string t, vector<vector<int>> &dp){
        
        // base case
        if(j == 0) return 1;
        if(i == 0 && j >= 1) return 0;
        
        // if it exists 
        if(dp[i][j] != -1) return dp[i][j]; 
        
        // if the characters match
        if(s[i-1] == t[j-1]){
            return dp[i][j] = getnumdistinctsubs(i-1,j-1,s,t,dp) + getnumdistinctsubs(i-1,j,s,t,dp); 
        }
        
        // if it dont match
        return dp[i][j] = getnumdistinctsubs(i-1,j,s,t,dp);        
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return getnumdistinctsubs(n,m,s,t,dp);
    }
};