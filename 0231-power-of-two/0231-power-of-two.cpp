class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ones = 0;
        
        if(n <= 0) return false;
        
        while(n){
            if(n % 2 != 0) ones += 1;
            n /= 2;
        }
        
        return ones == 1;
    }
};