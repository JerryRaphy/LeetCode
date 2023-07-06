class Solution {
public:
    bool canJump(vector<int>& A) {
         
        int n = A.size();
        if(n == 1) return true;

        if(A[0] == 0) return false;

        int st = 0;
        int en = A[0];
        
        while(en < n-1){
            int next_max = en;
            while(st <= en){
                next_max = max(next_max,A[st] + st);
                st += 1;
            }
            
            if(next_max == en) return false;
            en = next_max;
        }

        return true;
    }
};