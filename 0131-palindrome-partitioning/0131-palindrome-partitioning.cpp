class Solution {
public:
    
    
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
    
   
    void solve(int idx, vector<string> &curr, string &s, vector<vector<string>> &res){
        if(idx == s.length()) {
            res.push_back(curr);
            return;
        }
        
        string substring;
        
        for(int i=idx ; i<s.length() ; ++i){
            substring.push_back(s[i]);
            if(ispalin(substring)){
                curr.push_back(substring);
                solve(i+1,curr,s,res);
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        solve(0,curr,s,res);
        return res;
    }
};