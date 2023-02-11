class Solution {
public:
    
    bool static comp(vector<int> A, vector<int> B){
        if(A[1] == B[1]) return A[2] > B[2];
        return A[1] < B[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = trips.size();
        sort(trips.begin(),trips.end(),comp);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;        
        int curr_passengers = 0;
        
        
        for(int i=0 ; i<n ; ++i){ 
            int st = trips[i][1];
            int en = trips[i][2];
            int pa = trips[i][0];
            
            while(!pq.empty() && pq.top().first <= st){
                 curr_passengers -= pq.top().second;
                 pq.pop();
            }
            
            curr_passengers += pa;
            pq.push({en,pa});
                        
            if(curr_passengers > capacity) return false;
        }
        
        return true;
    }
};