class Solution {
public:
    
    
    vector<int> parent;
    vector<int> sz;
    
    int findparent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findparent(parent[node]);
    }
    
    void Union(int A, int B){
        int p1 = findparent(A);
        int p2 = findparent(B);

        
        if(p1 != p2){
            if(sz[p1] < sz[p2]) swap(p1,p2);
            parent[p2] = p1;
            sz[p1] += sz[p2];
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        parent.resize(n*n,0);
        sz.resize(n*n,0);
        
        
        vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(grid[i][j] == 1){
                    int cell = (n * i) + j;
                    parent[cell] = cell;
                    sz[cell] = 1;
                }
            }
        }
        
        
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                
                if(grid[i][j] == 1){
                    int cellA = (n * i) + j;
                    
                    for(auto move : moves){
                        int x = i + move.first;
                        int y = j + move.second;
                        
                        if(x < 0 || y < 0 || x >= n || y >= n || !grid[x][y]) continue;
                        
                        int cellB = (x * n) + y;
                        Union(cellA,cellB);
                
                    }
                }
            }
        }
    
        int res = *max_element(sz.begin(),sz.end());
        
         for(int i=0 ; i<n ; ++i){
             for(int j=0 ; j<n ; ++j){
                 if(grid[i][j] == 0){
                     
                     int current_size = 1;
                     unordered_set<int> st;
                     
                     for(auto move : moves){
                        int x = i + move.first;
                        int y = j + move.second;
                        
                        if(x < 0 || y < 0 || x >= n || y >= n || !grid[x][y]) continue;
                        
                        int cellB = (x * n) + y;
                        int parentB = findparent(cellB);
                         
        
                         
                        if(st.find(parentB) == st.end()){
                             current_size += sz[parentB];
                             st.insert(parentB);
                        }
                    }
                     
                    res = max(res,current_size); 
                     
                 }
             }
         }
        
         return res;
    }
};