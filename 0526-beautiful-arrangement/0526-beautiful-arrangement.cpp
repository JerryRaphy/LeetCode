class Solution {
public:
    
    
    
    void solve(int idx, vector<int> &perm, int &cnt){
       
        int n = perm.size();
        
        if(idx == n - 1){
            bool check = true;
            for(int i=0 ; i<n ; ++i){
                if(perm[i] % (i+1) != 0 && (i+1) % perm[i] != 0){
                    check = false;
                    break;
                }
            }
            
            if(check) ++cnt;
            return;
        }
        
        for(int i=idx ; i<n ; ++i){
            swap(perm[i],perm[idx]);
            if(perm[idx] % (idx + 1) == 0 || (idx + 1) % perm[idx] == 0) solve(idx+1,perm,cnt);
            swap(perm[i],perm[idx]);
        }
        return;
    }
    
    int countArrangement(int n) {
    
        vector<int> perm(n);
        for(int i=0 ; i<n ; ++i){
            perm[i] = i + 1;
        }
        
        int cnt = 0;
        solve(0,perm,cnt);
        return cnt;
    }
};