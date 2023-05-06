class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int zero = 0;
        
        for(auto num : nums){
            if(num < 0) neg += 1;
            else if(num > 0) pos += 1;
            else zero += 1;
        }
        
        if(zero > 0) return 0;
        if(neg % 2 != 0) return -1;
        return 1;
    }
};