class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int len = 1;
        
        vector<int> count_bits(33,0);
        
        int r = 0;
        int l = 0;
        
        while(r < n){
            
            int num = nums[r];
            int temp = 0;
            
            while(num){
                int mod = num % 2;
                if(mod == 1) count_bits[temp]++;
                num /= 2;
                ++temp;
            }
            
            bool check = true;
            
            
            for(int i=0 ; i<33 ; ++i){
                if(count_bits[i] > 1){
                    check = false;
                    break;
                }
            }
            
            if(!check){
                len = max(len,r-l);
                
                while(l <= r){
                    num = nums[l];
                    temp = 0;
                    while(num){
                        int mod = num % 2;
                        if(mod == 1) count_bits[temp]--;
                        num /= 2;
                        ++temp;
                    }
                    
                    check = true;
                    
                    for(int i=0 ; i<33 ; ++i){
                        if(count_bits[i] > 1){
                            check = false;
                            break;
                        }
                    }
                    
                    l += 1;
                    
                    if(!check) continue; 
                    else break;            
                }
            
                len = max(len,r-l);
            }
            ++r;
        }
        
        len = max(len,r-l);
        return len;
    }
};