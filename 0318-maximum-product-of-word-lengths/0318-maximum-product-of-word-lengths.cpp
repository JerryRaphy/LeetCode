class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        map<string,vector<bool>> mp;
        
        for(int i=0 ; i<n ; ++i){
            
            vector<bool> freq(26,false);
            
            for(int j=0 ; j<words[i].length() ; ++j){
                freq[words[i][j] - 'a'] = true;
            }
            mp[words[i]] = freq;
        }
        
        int len = 0;
        
        
        for(int i=0 ; i<n ; ++i){
            
            vector<bool> curr = mp[words[i]];
            
            for(int j=i+1 ; j<n ; ++j){
                
                vector<bool> temp = mp[words[j]];
                bool possible = true;
                
                for(int k=0 ; k<26 ; ++k){
                    if(curr[k] && temp[k]) {
                        possible = false;
                        break;
                    }
                }
                
                if(possible){
                    int currlen = words[i].length() * words[j].length();
                    len = max(len,currlen);
                }
            }
        }
        
        
        return len;
    }
};