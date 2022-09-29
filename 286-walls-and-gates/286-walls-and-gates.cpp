#define ll long long int

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        
        ll INF = 2147483647;
        queue<pair<pair<int,int>,int>> q;
        set<pair<int,int>> st;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(rooms[i][j] == 0) {
                    st.insert({i,j});
                    q.push({{i,j},0});
                }
            }
        }
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        
        
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            if(rooms[r][c] == INF) rooms[r][c] = d;
            
            for(int i=0 ; i<4 ; ++i){
                int x = r + dx[i];
                int y = c + dy[i];
                if(x>=0 && x<n && y>=0 && y<m){
                    if(st.find({x,y}) == st.end() && rooms[x][y] == INF){
                        st.insert({x,y});
                        q.push({{x,y},d+1});
                    }
                }
            }
        }
        return;
    }
};