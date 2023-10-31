class Solution {
public:
    
    void getpartitions(int idx, vector<string> curr, string s, vector<vector<string>> &res, int n, 
                      vector<vector<bool>> &ispalin){
        
        if(idx == n) {
            res.push_back(curr);
            return;
        }
        
        string temp;
        
        for(int i=idx ; i<n ; ++i){
            temp.push_back(s[i]);
            if(s[idx] == s[i] && (i - idx <= 2 || ispalin[idx+1][i-1])){
                ispalin[idx][i] = true;
                curr.push_back(temp);
                getpartitions(i+1,curr,s,res,n,ispalin);
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        vector<vector<bool>> ispalin(n,vector<bool>(n,false));
        
        getpartitions(0,curr,s,res,n,ispalin);
        
        return res;
        
    }
};