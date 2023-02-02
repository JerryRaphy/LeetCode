class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        sort(events.begin(),events.end());
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int maxprofit = 0;
        int maxi = 0;
        
        for(int i=0 ; i<n ; ++i){
            while(!pq.empty() && pq.top().first < events[i][0]){
                maxi = max(maxi,pq.top().second.second);
                pq.pop();
            }
            
            maxprofit = max(maxprofit,maxi + events[i][2]);
            pq.push({events[i][1],{events[i][0],events[i][2]}});
        }
        
        return maxprofit;
        
    }
};