#define ll long long int

class Solution {
public:
    
    bool ispossible(int val, int n, int index, int maxSum){
        
        ll curr_sum = 0;
        
        ll rse = n - index - 1;
        ll have = val - 1;
        
        ll low  = val - rse;
        if(low <= 0) low = 1;
        ll high = val - 1;
        
        ll f = low - 1;
            
        curr_sum += ((high * (high + 1)) / 2) - ((f * (f + 1)) / 2);
        if(rse - have > 0) curr_sum += rse - have;
        
        curr_sum += val;
    
        ll lse = index;
        low = val - index;
        if(low <= 0) low = 1;
        f = low - 1;
        
        curr_sum += ((high * (high + 1)) / 2) - ((f * (f + 1)) / 2);
        if(lse - have > 0) curr_sum += lse - have;
          
        if(curr_sum <= maxSum) return true;
        return false;
            
    }
    
    int maxValue(int n, int index, int maxSum) {
        
        int l = 1;
        int r = maxSum;
        
        int res = l;
    
        while(l <= r){
            
            int mid = l + (r - l) / 2;
            if(ispossible(mid,n,index,maxSum)){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
            
        }
        
        
        return res;
    }
};