class Solution {
public:
    int divide(long long int dividend, long long int divisor) {
    
        long long int t = 0;
        long long int q = 0;
        
        int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        for(long long i=31 ; i>=0 ; --i){
            if(t + (divisor << i) <= dividend){
                t += divisor << i;
                q = q | (1LL << i);
            }
        }
        
        if(sign == -1) q = -q;
    
        if(q > INT_MAX) return INT_MAX;
        if(q < INT_MIN) return INT_MIN;
        return q;
        
    }
};