class Solution {
public:
    
    int total = 0;
    vector<int> ans;
    
    
    void solve(int idx, int bobarrows, vector<int> &arrows, vector<int> &res, int curr_total){
        
        if(idx == -1 || bobarrows <= 0){
            
            if(curr_total > total){
                total = curr_total;
                
                if(bobarrows > 0) res[0] += bobarrows;
                ans = res;
                res[0] = 0;
            }
            
            return;
        }
        
        
        if(bobarrows > arrows[idx]){
            res[idx] = arrows[idx] + 1;
            solve(idx-1, bobarrows - res[idx], arrows, res, curr_total + idx);
            res[idx] = 0;
        }
        
        solve(idx-1,bobarrows,arrows,res,curr_total); 
        return;

    }
    
    vector<int> maximumBobPoints(int bobarrows, vector<int>& arrows) {
        
        int n = arrows.size();
        vector<int> res(12,0);
        solve(11,bobarrows,arrows,res,0);
        return ans;
    }
};