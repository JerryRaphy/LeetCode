class Solution {
public:
    
    map<string,int> mp;

    bool dfs(string curr){
        
        int n = curr.length();
        for(int i=1 ; i<n ; ++i){
            string prefix = curr.substr(0,i);
            string suffix = curr.substr(i);
            
            if(mp[prefix] && (mp[suffix] || dfs(suffix))) return true;
        }
        
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto word : words) mp[word]++;
        vector<string> res;
        
        
        for(auto word : words){
            if(dfs(word)){
                res.push_back(word);
            }
        }
        
        return res;
    }
};