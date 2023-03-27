class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(2,0));
        
        if(s[n - 1] == '0') dp[n - 1][1] = 1;
        else dp[n - 1][0] = 1;
        
        for(int i=n-2 ; i>=0 ; --i){
            if(s[i] == '1'){
                dp[i][1] = dp[i + 1][1];
                dp[i][0] = 1 + min(dp[i+1][0],dp[i+1][1]);
            }
            else{
                dp[i][0] = min(dp[i+1][0],dp[i+1][1]);
                dp[i][1] = 1 + dp[i+1][1];
            }
        }
        
        return min(dp[0][0],dp[0][1]);
        
    }
};