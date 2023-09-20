class Solution {
public:
    
    
int solve(vector<int> &compos, vector<int> &stock, vector<int> &cost, int budget){
    
    int l = 0;
    int r = 1e9;
    int n = compos.size();
    long long int max_alloys = 0;
    
    while(l <= r){
        
        long long int mid = l + (r - l) / 2;
        long long int current_cost = 0;
        
        for(int i=0 ; i<n ; ++i){
            long long int metals_needed = (compos[i] * mid) - stock[i];
            if(metals_needed < 0) metals_needed = 0;
            
            current_cost += (metals_needed * cost[i] * 1LL);
        }
        
        if(current_cost <= budget){
            max_alloys = mid;
            l = mid + 1;
        }
        else r = mid - 1;
        
    }
    
    return max_alloys;
    
}
    
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        
        int res = 0;
        for(int i=0 ; i<k ; ++i){
            res = max(res,solve(composition[i],stock,cost,budget));
        }
        
        return res;
    }
};