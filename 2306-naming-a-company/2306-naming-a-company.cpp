#define ll long long

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        int n = ideas.size();
        map<char,set<string>> mp;
        ll names = 0;
        
        for(int i=0 ; i<n ; ++i){
            char ch = ideas[i][0];
            string s = ideas[i].substr(1);
            mp[ch].insert(s);
        }
        
        for(int i=0 ; i<25 ; ++i){
            char ch1 = char(i+97);
            
            for(int j=i+1 ; j<26 ; ++j){
                
                ll mutual = 0;
                char ch2 = char(j+97);
                
                for(auto word : mp[ch1]){
                    if(mp[ch2].find(word) != mp[ch2].end()) mutual += 1;
                }
                
                names += 2LL * (mp[ch1].size() - mutual) * (mp[ch2].size() - mutual);
            }
            
        }
        
        return names;
    }
};