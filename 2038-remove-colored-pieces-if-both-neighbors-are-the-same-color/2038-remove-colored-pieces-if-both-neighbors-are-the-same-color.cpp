class Solution {
public:
    bool winnerOfGame(string colors) {
        
        
        int n = colors.size();
        
        int l = 0;
        int r = 0;
        
        int A = 0;
        int B = 0;
        
        while(r < n){
            if(colors[r] == colors[l]) r += 1;
            else{
                int len = r - l;
                if(len >= 3) len -= 2;
                else{
                    l = r;
                    continue;
                }
                if(colors[l] == 'A') A += len;
                else B += len;
                l = r;
            }
        }
        
        int len = r - l;
        if(len  >= 3){
            len -= 2;
            if(colors[l] == 'A') A += len;
            else B += len;
        }
    
            
        if(B >= A) return false;
        return true;
        
    }
};