class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int i = 0;
        
        while(i < n - 1){
            if(pq.size() == ladders) break;
            if(heights[i] < heights[i+1]) pq.push(heights[i+1] - heights[i]);
            i += 1;
        }
        
      
        
        while(i < n-1){
            if(heights[i] < heights[i+1]){
                int jump = heights[i+1] - heights[i];
                if(!pq.empty() && jump > pq.top()){
                    int temp = pq.top();
                    if(bricks >= temp){
                        pq.pop();
                        bricks -= temp;
                        pq.push(jump);
                    }
                    else break;
                }
                else{
                    if(bricks >= jump) bricks -= jump;
                    else break;
                }
                i += 1;
            }
            else i += 1;
        }
        
        return i;
    }
};