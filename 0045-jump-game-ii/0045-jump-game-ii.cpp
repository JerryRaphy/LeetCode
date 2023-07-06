class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return 0;
        
        int st = 0;
        int en = nums[0];
        int jumps = 1;
        
        while(en < n - 1){
            
            int max_jump = st;
            while(st <= en){
                max_jump = max(max_jump,st + nums[st]);
                st += 1;
            }
            
            en = max_jump;
            jumps += 1;
        }
        
        return jumps;
    }
};