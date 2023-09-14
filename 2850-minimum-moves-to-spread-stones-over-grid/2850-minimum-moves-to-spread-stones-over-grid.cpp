class Solution {
public:
    
    vector<pair<int,int>> zeroes;
    vector<pair<int,int>> nonzeroes;
    int res = 1e9;
    
    int dist(pair<int,int> x, pair<int,int> y){
        return abs(x.first - y.first) + abs(x.second - y.second);
    }
    
    void solve(vector<int> order, vector<bool> take){
        
        // base case
        if(order.size() == take.size()){
            int curr = 0;
            for(int i=0 ; i<zeroes.size() ; ++i){
                curr += dist(zeroes[order[i]],nonzeroes[i]);
            }    
        
            res = min(res,curr);
        }
        
        
        for(int i=0 ; i<take.size() ; ++i){
            if(take[i]) continue;
            
            take[i] = true;
            order.push_back(i);
            
            solve(order,take);
            
            order.pop_back();
            take[i] = false;
        }
        
        return;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
                
        zeroes.clear();
        nonzeroes.clear();
        
        for(int i=0 ; i<3 ; ++i){
            for(int j=0 ; j<3 ; ++j){
                if(grid[i][j] != 0) { // non - zeroes
                    for(int count = 0 ; count < grid[i][j] - 1 ; count++){
                        nonzeroes.push_back({i,j});
                    }
                }
                else zeroes.push_back({i,j});
            }
        }
        
        vector<int> order;
        vector<bool> take(zeroes.size(),false);
        
        solve(order,take);
        return res;
        
    }
};