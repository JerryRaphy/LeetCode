class Solution {
public:
    
    
       bool isregularexpression(int i, int j, string A, string B, int n, int m, vector<vector<int>> &memo){
        if(i >= n && j >= m) return true;
        if(j >= m) return false;

        if(memo[i][j] != -1) return memo[i][j];
        bool match = false;
        if(i < n && (A[i] == B[j] || B[j] == '.')) match = true;

        if(j+1 < m && B[j+1] == '*')
            if(isregularexpression(i,j+2,A,B,n,m,memo) || (match && isregularexpression(i+1,j,A,B,n,m,memo))) return memo[i][j] = true;
           
        if(match) return memo[i][j] = isregularexpression(i+1,j+1,A,B,n,m,memo);
        return memo[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        return isregularexpression(0,0,s,p,n,m,memo);
    }
};