class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialroads) {
        
        map<pair<int,int>,vector<vector<int>>> mp;
        map<pair<int,int>,int> cost;
        
        for(auto it : specialroads){
            
            int f = abs(it[2] - it[0]) + abs(it[3] - it[1]);
            
            if(it[4] < f) {
                mp[{it[0],it[1]}].push_back({it[2],it[3],it[4]});
                cost[{it[0],it[1]}] = INT_MAX;
                cost[{it[2],it[3]}] = INT_MAX;
            }
        }
        
        int min_dist = abs(target[1] - start[1]) + abs(target[0] - start[0]);   
        queue<vector<int>> q;
        
        cost[{start[0],start[1]}] = 0;
        cost[{target[0],target[1]}] = min_dist;
        
        q.push({start[0],start[1],0});
        
        while(!q.empty()){
            
            int x = q.front()[0];
            int y = q.front()[1];
            int c = q.front()[2];
            
            q.pop();
        
            // if there are special roads connected to this cell, use them if we can reach that cell at a lower cost
            
            for(auto it : mp[{x,y}]){
                
                int to_x = it[0];
                int to_y = it[1];
                int to_c = it[2];
                
                if((c + to_c) < cost[{to_x,to_y}]){
                    cost[{to_x,to_y}] = c + to_c;
                    q.push({to_x,to_y,c + to_c});
                }
            
            }
            
            // try to go to any of the special roads from here
            
            for(auto it : mp){                

                int to_x = it.first.first;
                int to_y = it.first.second;
                int to_c = abs(to_x - x) + abs(to_y - y);
                
                if((c + to_c) < cost[{to_x,to_y}]){
                    cost[{to_x,to_y}] = c + to_c;
                    q.push({to_x,to_y,c + to_c});
                }
            }
            
            int res = abs(target[0] - x) + abs(target[1] - y);
            
            if((res + c) < cost[{target[0],target[1]}]){
                cost[{target[0],target[1]}] = res + c;
                q.push({target[0],target[1],res + c});
            }
        }
        

        return cost[{target[0],target[1]}];
    }
};