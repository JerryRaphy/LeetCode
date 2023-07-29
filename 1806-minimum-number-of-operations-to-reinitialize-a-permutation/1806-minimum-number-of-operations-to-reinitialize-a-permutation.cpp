class Solution {
public:
    int reinitializePermutation(int n) {    
        
        vector<int> v(n);
        for(int i=0 ; i<n ; ++i) v[i] = i;
        
        int ops = 0;
        while(true){
            
            vector<int> curr(n);
            for(int i=0 ; i<n ; ++i){
                if(i % 2 == 0) curr[i] = v[i / 2];
                else curr[i] = v[n / 2 + (i - 1) / 2];
            }
            
            
            ops += 1;
            bool f = true;
            
            for(int i=0 ; i<n ; ++i){
                if(curr[i] != i) f = false;
            }
            
            if(f) break;
            v = curr;
            
        }
        
        return ops;
    }
};