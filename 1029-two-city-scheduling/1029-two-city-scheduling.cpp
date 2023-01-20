class Solution {
public:
        
    vector<vector<vector<int>>> memo;
    
    int helper(vector<vector<int>>& costs, int i, int c1, int c2)
    {
        
        
        if(c1 == 0 && c2 == 0) return 0;
        
        if(c1 < 0 || c2 < 0) return 1e9;
            
        if(memo[i][c1][c2] != -1) return memo[i][c1][c2];
           
        int ans1 = costs[i][0] + helper(costs, i+1, c1-1, c2);
        int ans2 = costs[i][1] + helper(costs, i+1, c1, c2-1);
        return  memo[i][c1][c2] = min(ans1, ans2);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        memo.resize(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = helper(costs, 0, n/2, n/2);
        return ans;
    }
};