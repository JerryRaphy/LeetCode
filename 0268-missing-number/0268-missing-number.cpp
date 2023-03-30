class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int x = nums.size();
        int n = nums.size();
        
        for(int i=0 ; i<n ; ++i){
            x = x ^ i ^ nums[i]; 
        }
        
        return x;
    }
};