class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        int n = sticks.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0 ; i<n ; ++i) pq.push(sticks[i]);
        int res = 0;
         
        if(n == 1) return 0;
        
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            res += a + b;
            pq.push(a + b);
        }
        
        return res;
    }
};