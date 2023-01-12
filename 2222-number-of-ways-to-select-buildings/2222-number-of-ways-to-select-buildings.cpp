class Solution {
public:
    long long dp[100001][4][3];
    long long solve(char prev,int i,int k,string &s){
        if(k == 0) return 1;
        if(i == s.size()) return 0;
        if(dp[i][k][prev - '0'] != -1) return dp[i][k][prev - '0'];
        
        long long op1 = 0;
        if(s[i] != prev) op1 = solve(s[i],i+1,k-1,s);
        long long op2 = solve(prev,i+1,k,s);
        return dp[i][k][prev - '0'] = op1 + op2;
    }
    long long numberOfWays(string s) {
        memset(dp,-1,sizeof dp);
        return solve('2',0,3,s);
    }
};