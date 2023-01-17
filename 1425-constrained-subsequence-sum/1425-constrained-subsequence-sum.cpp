class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        
        pq.push({nums[0],0});
        int sum = nums[0];
        int i = 1;
            
        while(i < n){
            
            int range = i - k;
            while(!pq.empty() && pq.top().second < range) pq.pop();
            
            int curr = max(nums[i],pq.top().first + nums[i]);
            pq.push({curr,i});
            sum = max(sum,curr);
            
            ++i;
        }
        
        return sum;
    }
};