class Solution {
 public:
  vector<vector<int>> dp;
  vector<int> res;
    
  int recur(int cap, vector<int>& aliceArrows, int ind) {
        // base case when bob firing capacity is zero or index becomes zero
        if (ind == 0 || cap == 0) return 0;
        int put = 0;

        // if element already in DP
        if (dp[ind][cap] != -1) {
          return dp[ind][cap];
        }

        if (cap > aliceArrows[ind - 1]) {
          put =
              ind - 1 + recur(cap - aliceArrows[ind - 1] - 1, aliceArrows, ind - 1);
        }
        int nput = recur(cap, aliceArrows, ind - 1);

        // if element not in DP then DP[index][capacity] = max(firing At index i,
        // not filing at index i); also if firing then bob will fire
        // aliceArrows[index]+1 to win that location and maximize profit
        return dp[ind][cap] = max(put, nput);
  }

  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int bobTotalArrow = numArrows;
        // res to store result, dp will be size 12*bobTotalArrow
        res.clear();
        res.resize(12, 0);

        dp.clear();
        dp.resize(13, vector<int>(bobTotalArrow + 1, -1));

        recur(bobTotalArrow, aliceArrows, 12);
      
        
     
      
        
        // computing result array from DP result
        int result = dp[12][bobTotalArrow];
        int total = 0;
        for (int i = 12, j = bobTotalArrow; i > 0 && result > 0; i--) {
          if(j == 0) break;
          if (result == dp[i - 1][j])
            continue;
          else {
            // This item is included.
            res[i - 1] = aliceArrows[i - 1] + 1;
            result -= (i - 1);
            j -= res[i - 1];
            total += res[i - 1];
          }
        }
        if (total < bobTotalArrow) {
          res[0] = bobTotalArrow - total;
        }
        
        
        return res;
  }
};