class Solution {
public:
    
    
    int getatmost(int target, vector<int> &nums){
        
        int n = nums.size();
        int cnt = 0;
        
        int l = 0;
        int r = 0;
        
        int sum = 0;
        
        while(r < n){
            
            sum += nums[r];
            
            if(sum <= target){
                cnt += r - l + 1;
            }
            else{
                while(l <= r && nums[l] == 0) l += 1;
                l += 1;
                cnt += r - l + 1;
                sum -= 1;
            }
            
            r += 1;
        }
        
        return cnt;
        
        
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        if(goal == 0) return getatmost(goal,nums);
        return getatmost(goal,nums) - getatmost(goal-1,nums);
    }
};