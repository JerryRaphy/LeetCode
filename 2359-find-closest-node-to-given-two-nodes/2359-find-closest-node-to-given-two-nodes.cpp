class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        int res = INT_MAX;
        int ans = -1;
        
        map<int,int> distfromnode1;
        queue<pair<int,int>> q;
        
        vector<bool> visited(n+1,false);
    
        distfromnode1[node1] = 0;
        q.push({node1,0});
        visited[node1] = true;
        
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            int child = edges[node];
            if(child == -1 || visited[child]) continue;
            
            visited[child] = true;
            distfromnode1[child] = dist + 1;
            q.push({child,dist+1});
            
        }
                
        visited.clear();
        visited.resize(n,false);
            
        while(!q.empty()) q.pop();
        
        q.push({node2,0});
        visited[node2] = true;
    
        

        while(!q.empty()){
       
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
                        
            if(distfromnode1.find(node) != distfromnode1.end()){
                int curr_res = max(distfromnode1[node],dist);
                if(curr_res < res){
                    res = curr_res;
                    ans = node;
                }
                else if(curr_res == res){
                    ans = min(ans,node);
                }
            }
            
            int child = edges[node];
            
            if(child == -1 || visited[child]) continue;
            visited[child] = true;
            q.push({child,dist+1});
            
        }
    
        return ans;
        
    }
};