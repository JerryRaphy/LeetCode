class Solution {
public:
    
    
    int bfs(int x, int y, int value, vector<vector<int>> &forest){
        
        int n = forest.size();
        int m = forest[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[x][y] = true;
        
        queue<pair<int,int>> q;
        q.push({x,y});
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        int res = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                int X = q.front().first;
                int Y = q.front().second;
                q.pop();

                if(forest[X][Y] == value) return res;

                for(int i=0 ; i<4 ; ++i){
                    int new_x = X + dx[i];
                    int new_y = Y + dy[i];

                    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || forest[new_x][new_y] == 0 || visited[new_x][new_y])
                        continue;

                    visited[new_x][new_y] = true;
                    q.push({new_x,new_y});
                }
            }
            res += 1;
            
        }
        
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
           
        int n = forest.size();
        int m = forest[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(forest[i][j] > 1) pq.push({forest[i][j],i,j});        
            }
        }
        
        int steps = 0;
        
        int x = 0;
        int y = 0;
        
        while(!pq.empty()){
            
            int get = bfs(x,y,pq.top()[0],forest);
            if(get == -1) return -1;
            else steps += get;
            
            
            
            x = pq.top()[1];
            y = pq.top()[2];
            pq.pop();
        }
        
        return steps;
    }
};