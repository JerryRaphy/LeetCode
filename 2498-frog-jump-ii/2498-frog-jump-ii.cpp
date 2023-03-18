class Solution {
public:
    
    
    bool ispossible(int jump, vector<int> stones, int n){
        
        int st = 0;
        int en = 1;
        
        // check if we can go forward direction
        while(st < (n - 1) && en < n){
            if(stones[en] - abs(stones[st]) > jump){
                if(en - 1 == st) return false;
                else{
                    st = en - 1;
                    stones[st] *= -1;
                }
            }  
            else en += 1;
        }
        
        // for(int i=0 ; i<n ; ++i) cout<<stones[i]<<" ";
        
        // now we will check for the reverse direction
        st = n - 1;
        en = st - 1;
        
        while(en >= 0 && st > 0){
            if(stones[en] > 0){
                  if(stones[st] - stones[en] <= jump){
                      st = en;
                      en -= 1;
                  }
                  else return false;  
            } 
            else en -= 1;
        }
        
        if(stones[st] - stones[0] > jump) return false;
        return true;
    }
    
    int maxJump(vector<int>& stones) {
        
        int n  = stones.size();
        int l = 0;
        int r = stones[n - 1];
        
        int res = r;        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(ispossible(mid,stones,n)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};