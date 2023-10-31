class Solution {
public:
    
    
    bool ispalin(string temp){
        
        int l = 0;
        int r = temp.length() - 1;
        
        while(l <= r){
            if(temp[l++] != temp[r--]) return false;
        }
        
        return true;
    }
    
    void getpartitions(int idx, vector<string> curr, string s, vector<vector<string>> &res, int n){
        
        if(idx == n) {
            res.push_back(curr);
        }
        
        string temp;
        
        for(int i=idx ; i<n ; ++i){
            temp.push_back(s[i]);
            if(ispalin(temp)){
                curr.push_back(temp);
                getpartitions(i+1,curr,s,res,n);
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        
        getpartitions(0,curr,s,res,n);
        
        return res;
        
    }
};