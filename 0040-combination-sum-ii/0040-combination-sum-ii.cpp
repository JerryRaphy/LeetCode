class Solution {
public:
    
void solve(int idx, int sum, vector<int> &A, int B, vector<int> &curr, vector<vector<int>> &res){
    
    if(sum == B) {
        res.push_back(curr);
    }
    
    if(idx == A.size() || sum > B) return;
    
    for(int i=idx ; i<A.size() ; ++i){
        
        if(i != idx && A[i] == A[i-1]) continue;
        
        sum += A[i];
        curr.push_back(A[i]);
        
        solve(i+1,sum,A,B,curr,res);
        
        curr.pop_back();
        sum -= A[i];            
    }
    
    return;
}
    
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        
        vector<vector<int>> res;
        sort(A.begin(),A.end());
        vector<int> curr;

        solve(0,0,A,B,curr,res);

        sort(res.begin(),res.end());
        return res;
    }
};