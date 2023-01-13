// memoization MCM but we can also do a binary search

class Solution {
public:
    
    int ispossible(int mid, int k, vector<int> &nums){
        int splits = 0;
        int sum = 0;
        int n = nums.size();
        
        for(int i=0 ; i<n ; ++i){
            sum += nums[i];
            if(sum > mid){
                ++splits;
                sum = nums[i];
            }
        }
        
        if(splits + 1 <= k) return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = INT_MIN;
        int r = 0;
        
        for(int i=0 ; i<n ; ++i){
            r += nums[i];
            l = max(l,nums[i]);
        }
        
        
        int ans = INT_MIN;
        while(l <= r){
            
            int mid = l + (r-l) / 2;  
            if(ispossible(mid,k,nums)){
                ans = mid;
                r = mid - 1;
            }
            else{ 
                l = mid + 1;
            }
        }
        
        return ans;
    }
};