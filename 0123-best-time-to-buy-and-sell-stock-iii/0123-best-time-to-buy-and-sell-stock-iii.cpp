class Solution {
public:
    int getprofit(int idx, vector<int> &prices, int buy, int transactions, vector<vector<vector<int>>> &dp){
        
        if(idx == prices.size() || transactions == 0) return 0;
        
        int curr_max_profit = 0;
        
        if(dp[idx][buy][transactions] != -1) return dp[idx][buy][transactions];
        
        // if buy is 0, meaning we haven't bought yet or buy later
        
        if(!buy){
            curr_max_profit = max(getprofit(idx+1,prices,1,transactions,dp) - prices[idx],getprofit(idx+1,prices,0,transactions,dp));
        }
        
        // if buy is 1, we will have to sell now or sell later
        if(buy){
            curr_max_profit = max(getprofit(idx+1,prices,0,transactions - 1,dp) + prices[idx],getprofit(idx+1,prices,1,transactions,dp));
        }
        
        return dp[idx][buy][transactions] = curr_max_profit;
      
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int buy = 0;
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return getprofit(0,prices,buy,2,dp);
    }
};