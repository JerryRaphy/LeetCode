class Solution {
public:
    
        void solve(int idx, vector<int> curr, int sum, vector<int> &candidates, int target, int n, vector<vector<int>> &res){
        
        if(sum == target){
            res.push_back(curr);
            return;
        }
        
        if(idx >= n) return;
        if(sum > target) return;
        
        
//         int end = idx + 1;
//         while(end < n && candidates[end] == candidates[idx]) end += 1;
            
        
//         // take one by one
//         for(int i=idx ; i<end ; ++i){
//             curr.push_back(candidates[i]);
//             solve(end,curr,sum + candidates[i],candidates,target,n,res);
//             curr.pop_back();
//         }
        
//         // general skip
//         solve(end,curr,sum,candidates,target,n,res);
        
         
        // taking the first
        curr.push_back(candidates[idx]);
        solve(idx+1,curr,sum + candidates[idx],candidates,target,n,res);
        curr.pop_back();
            
        int i = idx;
        while(i < n && candidates[i] == candidates[idx]){
            i += 1;
        }
        idx = i-1;
            
        // not take
        solve(idx+1,curr,sum,candidates,target,n,res);
        
        
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        int n = candidates.size();
        
        sort(candidates.begin(),candidates.end());
        
        solve(0,curr,0,candidates,target,n,res);
        return res;
    }
};