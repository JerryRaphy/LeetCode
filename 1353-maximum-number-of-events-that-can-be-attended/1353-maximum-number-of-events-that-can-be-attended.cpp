class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        sort(events.begin(),events.end());
        int ans = 0;
        int i = 0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int d=1 ; d<=100000 ; ++d){
            
            while(!pq.empty() && pq.top() < d) pq.pop();
            
            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i += 1;
            }
            
            if(!pq.empty()){
                pq.pop();
                ans += 1;
            }
            
            if(pq.empty() && i == n) break;
        }
        
        return ans;
        
    }
};