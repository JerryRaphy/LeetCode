class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int mid = n / 2;
        int l = 0;
        int r = mid;
        int cnt = 0;
        
        while(l < mid && r < n){
            if(nums[l] * 2 <= nums[r]){
                cnt += 2;
                l += 1;
                r += 1;
            }
            else{
                r += 1;
            }
        }
        
        return cnt;
        
    }
};