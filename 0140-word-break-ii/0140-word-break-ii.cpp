class Solution {
public:
    
    void dfs(int idx, string curr, string A, vector<string> &B, vector<string> &v, int n){
    
        if(idx == n){
            v.push_back(curr);
            return;
        }

        for(auto word : B){
            int len = word.length();
            if(idx+len <= n && A.substr(idx,len) == word){
                if(curr.length() == 0) dfs(idx+len,word,A,B,v,n);
                else dfs(idx+len,curr + " " + word,A,B,v,n);
            }
        }

        return;
    }

    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         
         int n = s.length();
         vector<string> v;
         string curr;
        
         dfs(0,curr,s,wordDict,v,n);
         return v;
    }
};