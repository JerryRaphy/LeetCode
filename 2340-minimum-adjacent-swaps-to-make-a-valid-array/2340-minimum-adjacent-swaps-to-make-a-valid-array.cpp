class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        
        int n = nums.size();
        
        int mx = nums[0];
        int mn = nums[0];
        
        int mx_pos = 0;
        int mn_pos = 0;
        
        for(int i=1 ; i<n ; ++i){
            if(nums[i] >= mx){
                mx = nums[i];
                mx_pos = i;
            }
            else if(nums[i] < mn){
                mn = nums[i];
                mn_pos = i;
            }
        }
            
        
        // when all of the elements are the same
        if(mn == mx) return 0;
        
        // case 1 when both of them are not overlapping
        if(mn_pos < mx_pos){
            return mn_pos + n - 1 - mx_pos;
        }
        
        // case 2 when they do overlap, first swap the pos which is nearer to its end
        if(n - mx_pos - 1 <= mn_pos){
            int f = n - mx_pos - 1;
            return f + (mn_pos - 1);    
        }
        
        
        return mn_pos + n - 1 - mx_pos - 1;
         
    }
};