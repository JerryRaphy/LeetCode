class Solution {
public:
   
    
    vector<int> prefix;
    int n;
    
    Solution(vector<int>& w) {
        n = w.size();
        prefix.resize(n,0);
        prefix[0] = w[0];
        for(int i=1 ; i<n ; ++i){
            prefix[i] = w[i] + prefix[i-1];
        }
    }
    
    int pickIndex() {
        float r = (float)rand() / RAND_MAX;
        float target = r * prefix.back();
        
        for(int i=0 ; i<n; ++i){
            if(target < prefix[i]) return i;
        }
        
        return n - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */