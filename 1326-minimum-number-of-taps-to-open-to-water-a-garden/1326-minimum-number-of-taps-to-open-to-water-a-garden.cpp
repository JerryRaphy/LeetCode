class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> jumps(n+1,0);
        
        for(int i=0 ; i<=n ; ++i){
            
            if(ranges[i] == 0) continue;
            int left  = max(0,i - ranges[i]);
            jumps[left] = max(jumps[left],i + ranges[i]);
        }
        
        int en = 0;
        int maxfarpossible = 0;
        int mn_taps = 0;
        
        for(int i=0 ; i<=n && en<n ; en = maxfarpossible){
            
            mn_taps += 1;
            while(i <= n && i <= en){
                maxfarpossible = max(maxfarpossible,jumps[i]);
                i += 1;
            }
            
            if(en == maxfarpossible) return -1;
        }
        
        return mn_taps;
    }
};