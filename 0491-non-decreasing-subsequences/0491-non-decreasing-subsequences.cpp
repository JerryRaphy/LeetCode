class Solution {
public:
    
    
    set<vector<int>> st;
    
    void solve(int idx, int prev, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, int n){
        
        if(idx == n) return;
        
        // if the current value is bigger than the prev value
        if(nums[idx] >= nums[prev]){
            curr.push_back(nums[idx]);
            if(!st.count(curr)){
                res.push_back(curr);
                st.insert(curr);
            }
            solve(idx+1,idx,nums,curr,res,n);
            curr.pop_back();
        }
        
        // skip and move on
        solve(idx+1,prev,nums,curr,res,n);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<vector<int>> res;
        
        vector<int> curr;
        for(int i=0 ; i<n ; ++i){
            curr.push_back(nums[i]);
            solve(i+1,i,nums,curr,res,n);
            curr.pop_back();
        }
        
        return res;
    }
};