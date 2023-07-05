class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<int,vector<int>> pq;
        
        
        if(k == 0) return nums[0];
        if(n == 1 && k % 2 != 0) return -1;
        if(k == 1) return nums[1];
        
        if(k > n) return *max_element(nums.begin(),nums.end());
        
        for(int i=0 ; i<k-1 ; ++i){
            pq.push(nums[i]);
        }

        if(k == n) return pq.top();
        return max(pq.top(),nums[k]);

    }
};