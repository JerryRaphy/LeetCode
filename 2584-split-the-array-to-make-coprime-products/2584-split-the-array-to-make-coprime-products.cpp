class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int> lstprime(1000001,0);
        
        for(int i=0 ; i<n ; ++i){
            
            int num = nums[i];
            
            while(num % 2 == 0){
                num /= 2;
                lstprime[2] = i;
            }
            
            
            for(int j=3 ; j<=sqrt(num) ; j += 2){
                
                while(num % j == 0){
                    num /= j;
                    lstprime[j] = i;
                }
                
            }
            
            if(num > 2) lstprime[num] = i;
        }
        
        
        
        int i = 0;
        int res = 0;
        
        while(i <= res){
                            
            int num = nums[i];
            // for each prime factor keep updating the result

            while(num % 2 == 0){
                res = max(res,lstprime[2]);
                num /= 2;
            }
            
            for(int j=3 ; j<=sqrt(num) ; j += 2){
                
                while(num % j == 0){
                    num /= j;
                    res = max(res,lstprime[j]);
                }
            }
            
            if(num > 2) res = max(res,lstprime[num]);
            
            i += 1;
        }
        
        return i == n ? -1 : i - 1;
        
    }
};