class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();   
        vector<int> res;
        
        map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        
        for(int i=0 ; i<n ; ++i){
            mp[nums[i]]++;
        }
        
        for(auto it : mp) pq.push({it.second,it.first});
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};