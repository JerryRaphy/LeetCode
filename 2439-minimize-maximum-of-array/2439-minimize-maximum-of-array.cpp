class Solution {
public:
    
    bool solve(int k, vector<int> nums){
        
        int n = nums.size();
        if(nums[0] > k) return false;
        long long int prev = nums[0];
        
        for(int i=1 ; i<n ; ++i){
            long long int diff = k - prev;
            prev = nums[i] - diff;
            if(prev > k) return false;
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int res = r;    
        
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(solve(mid,nums)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        
        return res;
    }
};