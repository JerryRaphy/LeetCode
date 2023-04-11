class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<set<int>> rows(n);
        vector<set<int>> cols(m);
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j) rows[i].insert(j);    
        }
        
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j) cols[i].insert(j);
        }
        
        rows[0].erase(0);
        cols[0].erase(0);
        dist[0][0] = 1;
        
        int r = 0;
        int c = 0;

        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            
            // moving rightward direction
            auto startingcol = rows[r].lower_bound(c + 1);
            vector<int> possible_cols;
            
            while(startingcol != rows[r].end() && *startingcol <= c + grid[r][c]){
                q.push({r,*startingcol});
                dist[r][*startingcol] = dist[r][c] + 1;
                possible_cols.push_back(*startingcol);
                startingcol++;
            }
            
            for(auto it : possible_cols){
                rows[r].erase(it);
                cols[it].erase(r);
            }
          
            // moving downward direction
            auto startingrow = cols[c].lower_bound(r + 1);
            vector<int> possible_rows;
            
            while(startingrow != cols[c].end() && *startingrow <= r + grid[r][c]){
                q.push({*startingrow,c});
                dist[*startingrow][c] = dist[r][c] + 1;
                possible_rows.push_back(*startingrow);
                startingrow++;
            }
            
            for(auto it : possible_rows){
                cols[c].erase(it);
                rows[it].erase(c);
            }
            
            
         }
         
         return dist[n-1][m-1];
    }
};