class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<int,vector<int>> pq;
        int mn = INT_MAX;
        int dev = INT_MAX;
        
        for(int i=0 ; i<n ; ++i){
            if(nums[i] % 2 == 0) {
                mn = min(mn,nums[i]);
                pq.push(nums[i]);
            }
            else {
                mn = min(mn,nums[i] * 2);
                pq.push(nums[i] * 2);
            }
        }
        
        while(!pq.empty()){
            
            int num = pq.top();
            pq.pop();
            
            if(num % 2 != 0) {
                dev = min(num - mn,dev);
                break;
            }
            
            dev = min(dev,num - mn);
            num /= 2;
            
            if(num < mn) mn = num;
            pq.push(num);
        }
        
        return dev;
    }
};