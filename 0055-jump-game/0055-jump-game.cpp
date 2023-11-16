class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int pos = 0;
        int max_jump = nums[0];
        
        while(max_jump < n - 1){
            
            int nextmax = max_jump;
            
            while(pos <= max_jump) {
                nextmax = max(nextmax,pos + nums[pos]);
                pos += 1;
            }
            
                  
            if(nextmax == max_jump) return false;
            
            pos = max_jump;
            max_jump = nextmax;
        }
        
        return true;
    }
};