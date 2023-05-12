class Solution {
public:
    
    
    int dfs(int i, vector<int> &cost, int &res, int n){
        if(i >= n) return 0;
        int a = dfs(i*2 + 1,cost,res,n);
        int b = dfs(i*2 + 2,cost,res,n);
        
        res += abs(a - b);
        return cost[i] + max(a,b);
    }
    
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        dfs(0,cost,res,n);
        return res;
    }
};