const int mod = 1e9 + 7;

class Solution {
public:
    
    
   long long int binpow(long long int a, long long int b) {
        if (b == 0)
            return 1;
        long long res = binpow(a, b / 2);
        if (b % 2)
            return ((res%mod) * ((res%mod) * (a%mod) % mod)) % mod;
        else
            return (res%mod * res%mod) % mod;
    }   
    
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long int res = 0;
        
        for(int i=0 ; i<n ; ++i){
            
            int mn = nums[i];
            
            int l = i + 1;
            int r = n - 1;
            int pos = -1;
            
            while(l <= r){
                int mid = l + (r - l) / 2;
                int mx = nums[mid];
                
                if(mx + mn <= target){
                    pos = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            
            if(pos != -1){
                long long int pw = binpow(2,pos-i);
                res = (res%mod + pw%mod) % mod;
            }
            else if(mn <= target / 2) res = (res + 1) % mod;
            
        }
        
        return int(res % mod);
    }
};