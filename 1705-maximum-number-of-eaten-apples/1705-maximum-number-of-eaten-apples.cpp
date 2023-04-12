class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        int n = apples.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int res = 0;
        int i = 0;
        int day = 0;
        
        while(i < n || !pq.empty()){
            
            if(i < n && apples[i] > 0 && days[i] > 0) pq.push({i + days[i] - 1,apples[i]});
            while(!pq.empty() && pq.top().first < day) pq.pop();
            
            if(!pq.empty()){
                int curr_day = pq.top().first;
                int curr_app = pq.top().second;
                pq.pop();
                
                res += 1;
                curr_app -= 1;
                
                if(curr_app != 0) pq.push({curr_day,curr_app});
            }

            i += 1;
            day += 1;
        }
        
        return res;
    }
};
        