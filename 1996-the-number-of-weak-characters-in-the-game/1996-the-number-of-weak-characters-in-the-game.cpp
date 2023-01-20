class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        
        int n = v.size();
        int maxattack = 0;
        
        for(int i=0 ; i<n ; ++i) maxattack = max(maxattack,v[i][0]);
        
        vector<int> maxdefence(maxattack+2,0);
        for(int i=0 ; i<n ; ++i){
            int att = v[i][0];
            int def = v[i][1];
            maxdefence[att] = max(maxdefence[att],def);
        }
        
        int cnt = 0;
        
        for(int i=maxattack-1 ; i>=0 ; --i){
            maxdefence[i] = max(maxdefence[i],maxdefence[i+1]);
        }
        
        
        for(int i=0 ; i<n ; ++i){
            int def = v[i][1];
            int att = v[i][0];
            if(def < maxdefence[att + 1]) ++cnt;
        }
        
        return cnt;
    }
};