class Solution {
public:
    
    
    int getmincost(int l , int r , vector<int> &cuts , vector<vector<int>> &dp){
        if(r < l) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int mini = INT_MAX;
        for(int i=l ; i<=r ; ++i){
            mini = min(mini , cuts[r+1] - cuts[l-1] + getmincost(l,i-1,cuts,dp) + getmincost(i+1,r,cuts,dp));
        }
        return dp[l][r] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(102,vector<int>(102,-1));
        return getmincost(1,m,cuts,dp);    
    }
};