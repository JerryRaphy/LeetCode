class Solution {
public:
    
    bool static comp(vector<int> A, vector<int> B){
        if(A[0] == B[0]) return A[1] < B[1];
        return A[0] < B[0];
    }

    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        
        vector<int> dp(n,1);
        
        for(int i=1 ; i<n ; ++i){
            for(int j=0 ; j<i ; ++j){
                if(pairs[i][0] > pairs[j][1] && dp[i] < (1 + dp[j])){
                    dp[i] = 1 + dp[j];
                }
            }
        }
        
        int len = 1;
        for(int i=0 ; i<n ; ++i) len = max(len,dp[i]);
        return len;
    }
};