class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        
        int n = lights.size();
        int max_bright = 0;
        int bright = 0;
        
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; ++i){
            v.push_back({lights[i][0] - lights[i][1],1});
            v.push_back({lights[i][0] + lights[i][1] + 1,-1});
        }
        
        sort(v.begin(),v.end());
        int res = -1;
        
        for(auto it : v){
            bright += it.second;
            if(bright > max_bright){
                max_bright = bright;
                res = it.first;
            }
        }
        return res;
    }
};