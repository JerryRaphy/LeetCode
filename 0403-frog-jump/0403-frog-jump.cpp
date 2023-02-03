class Solution {
public:
    
    

    vector<vector<int>> dp;
    
    bool helper(vector<int> &stones, int lastindex, int currindex){
        
        int n = stones.size();
        
        if(stones[1] != 1) return false;
        
        if(currindex == n - 1) return true;
        
        if(dp[lastindex][currindex] != -1) return dp[lastindex][currindex];
        
        int lastjump = stones[currindex] - stones[lastindex];
        
        int nextindex = currindex + 1;
        
        while(nextindex < n && stones[nextindex] <= stones[currindex] + lastjump + 1){
            
            int nextjump = stones[nextindex] - stones[currindex];
            int currjump = nextjump - lastjump;
            
            if(currjump >= -1 && currjump <= 1){
                if(helper(stones,currindex,nextindex)) return dp[lastindex][currindex] = 1;
            }
            
            nextindex += 1;
        }
        
        return dp[lastindex][currindex] = 0;
    }
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        
        dp.resize(n+1,vector<int>(n+1,-1));
        return helper(stones,0,1);
    }
};