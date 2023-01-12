class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<int> indegrees(n+1,0);
        int m = relations.size();
        int sems = 0;
        
        vector<vector<int>> graph(n+1);
        
        for(int i=0 ; i<m ; ++i){
            graph[relations[i][0]].push_back(relations[i][1]);
            indegrees[relations[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0 ; i<n ; ++i){
            if(indegrees[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                
                for(auto child : graph[node]){
                    indegrees[child]--;
                    if(indegrees[child] == 0) q.push(child);
                }
            }
            ++sems;
        }
        
        for(int i=0 ; i<n ; ++i) {
            if(indegrees[i] > 0) return -1;
        }
        return sems;
    }
};