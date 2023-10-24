class Solution {
public:
    
    void solve(int idx, vector<int> &curr, int sum, vector<int> &candidates, int target, int n, vector<vector<int>> &res){
        
        if(idx >= n) return;
        
        if(sum > target) return;
        
        if(sum == target){
            res.push_back(curr);
            return;
        }
        
        
        // keep taking the first
        curr.push_back(candidates[idx]);
        solve(idx,curr,sum + candidates[idx],candidates,target,n,res);
        curr.pop_back();
            
        // not take
        solve(idx+1,curr,sum,candidates,target,n,res);
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        int n = candidates.size();
            
    
        solve(0,curr,0,candidates,target,n,res);
        return res;
    }
};