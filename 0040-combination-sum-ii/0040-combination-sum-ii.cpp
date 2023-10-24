class Solution {
public:
    
        void solve(int idx, vector<int> curr, int sum, vector<int> &candidates, int target, int n, vector<vector<int>> &res){
        
        if(sum == target){
            res.push_back(curr);
            return;
        }
        
        if(idx >= n) return;
        if(sum > target) return;
                
        int end = idx + 1;
        while(end < n && candidates[end] == candidates[idx]) end += 1;
        
     
        // general skip
        solve(end,curr,sum,candidates,target,n,res);
        
        int s = sum;
            
        // take one by one
        for(int i=idx ; i<end ; ++i){
            curr.push_back(candidates[i]);
            s += candidates[i];
            solve(end,curr,s,candidates,target,n,res);
        }

           
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