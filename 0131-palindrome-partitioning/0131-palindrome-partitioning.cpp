class Solution {
public:
    
    /*
    bool ispalin(string &substring){
        int l = 0;
        int r = substring.length() - 1;
        
        while(l < r){
            if(substring[l] != substring[r]) return false;
            l += 1;
            r -= 1;
        }
        
        return true;
    }
    */
    
   
    void solve(int idx, vector<string> &curr, string &s, vector<vector<string>> &res, vector<vector<bool>> &dp){
        if(idx == s.length()) {
            res.push_back(curr);
            return;
        }
        
        string substring;
        
        for(int i=idx ; i<s.length() ; ++i){
            substring.push_back(s[i]);
            if(s[idx] == s[i] && (i - idx <= 2 || dp[idx+1][i-1])){
                dp[idx][i] = true; 
                curr.push_back(substring);
                solve(i+1,curr,s,res,dp);
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        solve(0,curr,s,res,dp);
        return res;
    }
};